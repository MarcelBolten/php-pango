--TEST--
Pango\Attribute\AttributeList::serialize()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\AttributeList;
use Pango\Attribute\SizeAttribute;

$attributeList = new AttributeList();
var_dump($attributeList->getAttributes());

$attrSize = new Size(10, 10, 20);
$attributeList->insert($attrSize);

var_dump($attributeList->getAttributes());
var_dump($attributeList->serialize());

try {
    $attributeList->serialize(123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
array(0) {
}
array(1) {
  [0]=>
  object(Pango\Attribute\SizeAttribute)#%d (3) {
    ["startIndex"]=>
    int(10)
    ["endIndex"]=>
    int(20)
    ["value"]=>
    int(10)
  }
}
string(13) "10 20 size 10"
Pango\Attribute\AttributeList::serialize() expects exactly 0 arguments, 1 given
