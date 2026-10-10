--TEST--
Pango\Attribute\AttributeList::insert()
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

$attrSize = new Size(10, 10, 20);

$attributeList->insert($attrSize);
var_dump($attributeList->getAttributes());

try {
    $attributeList->insert();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->insert($attrSize, 123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->insert(array());
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
array(2) {
  [0]=>
  object(Pango\Attribute\Size)#%d (3) {
    ["startIndex"]=>
    int(10)
    ["endIndex"]=>
    int(20)
    ["value"]=>
    int(42)
  }
  [1]=>
  object(Pango\Attribute\Size)#%d (3) {
    ["startIndex"]=>
    int(10)
    ["endIndex"]=>
    int(20)
    ["value"]=>
    int(10)
  }
}
Pango\Attribute\AttributeList::insert() expects exactly 1 argument, 0 given
Pango\Attribute\AttributeList::insert() expects exactly 1 argument, 2 given
Pango\Attribute\AttributeList::insert(): Argument #1 ($attr) must be of type Pango\Attribute\Attribute, array given
