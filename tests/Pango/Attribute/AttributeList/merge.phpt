--TEST--
Pango\Attribute\AttributeList::merge()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AttributeList;

$attributeList = new AttributeList("10 20 size 10");
var_dump($attributeList->getAttributes());

$attributeList2 = new AttributeList("20 30 size 20");
var_dump($attributeList2->getAttributes());

$attributeList->merge($attributeList2);

var_dump($attributeList->serialize());

try {
    $attributeList->merge();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->merge($attributeList2, 123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->merge(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
array(1) {
  [0]=>
  object(Pango\Attribute\Size)#2 (3) {
    ["startIndex"]=>
    int(10)
    ["endIndex"]=>
    int(20)
    ["value"]=>
    int(10)
  }
}
array(1) {
  [0]=>
  object(Pango\Attribute\Size)#3 (3) {
    ["startIndex"]=>
    int(20)
    ["endIndex"]=>
    int(30)
    ["value"]=>
    int(20)
  }
}
string(27) "10 20 size 10
20 30 size 20"
Pango\Attribute\AttributeList::merge() expects exactly 1 argument, 0 given
Pango\Attribute\AttributeList::merge() expects exactly 1 argument, 2 given
Pango\Attribute\AttributeList::merge(): Argument #1 ($other) must be of type Pango\Attribute\AttributeList, array given
