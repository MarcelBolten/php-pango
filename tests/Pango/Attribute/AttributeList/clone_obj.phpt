--TEST--
Pango\Attribute\AttributeList clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AttributeList;

$attributeList = new AttributeList();
var_dump($attributeList);

$copy = clone $attributeList;
var_dump($copy);
?>
--EXPECT--
object(Pango\Attribute\AttributeList)#1 (0) {
}
object(Pango\Attribute\AttributeList)#2 (0) {
}
