--TEST--
Pango\Attribute\AttributeList::change()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AttributeList;
use Pango\Attribute\Size;

$attributeList = new AttributeList("10 20 size 42");
var_dump($attributeList->getAttributes());

$attrSize = new Size(10);
$attrSize->startIndex = 12;
$attrSize->endIndex = 18;

$attributeList->change($attrSize);
var_dump($attributeList->getAttributes());

try {
    $attributeList->change();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->change($attrSize, 123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->change(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

?>
--EXPECTF--
array(1) {
  [0]=>
  object(Pango\Attribute\Size)#%d (3) {
    ["startIndex"]=>
    int(10)
    ["endIndex"]=>
    int(20)
    ["value"]=>
    int(42)
  }
}
array(3) {
  [0]=>
  object(Pango\Attribute\Size)#%d (3) {
    ["startIndex"]=>
    int(10)
    ["endIndex"]=>
    int(12)
    ["value"]=>
    int(42)
  }
  [1]=>
  object(Pango\Attribute\Size)#%d (3) {
    ["startIndex"]=>
    int(12)
    ["endIndex"]=>
    int(18)
    ["value"]=>
    int(10)
  }
  [2]=>
  object(Pango\Attribute\Size)#%d (3) {
    ["startIndex"]=>
    int(18)
    ["endIndex"]=>
    int(20)
    ["value"]=>
    int(42)
  }
}
Pango\Attribute\AttributeList::change() expects exactly 1 argument, 0 given
Pango\Attribute\AttributeList::change() expects exactly 1 argument, 2 given
Pango\Attribute\AttributeList::change(): Argument #1 ($attr) must be of type Pango\Attribute\Attribute, array given
