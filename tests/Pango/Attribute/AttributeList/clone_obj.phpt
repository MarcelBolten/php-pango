--TEST--
Pango\Attribute\AttributeList clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\AttributeList;

$attributeList = new AttributeList();
var_dump($attributeList);

$copy = clone $attributeList;
var_dump($copy);
?>
--EXPECT--
object(Pango\Attribute\AttributeList)#1 (1) {
  ["string-representation"]=>
  string(0) ""
}
object(Pango\Attribute\AttributeList)#2 (1) {
  ["string-representation"]=>
  string(0) ""
}
