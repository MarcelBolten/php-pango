--TEST--
Pango\Attribute\AttributeIterator clone object handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\AttributeList;

$attrList = new AttributeList("0 10 size 42");
var_dump($attrList);
$attrIter = $attrList->getIterator();
var_dump($attrIter);
$attrIterClone = clone $attrIter;
var_dump($attrIterClone);
?>
--EXPECTF--
object(Pango\Attribute\AttributeList)#%d (1) {
  ["string-representation"]=>
  string(12) "0 10 size 42"
}
object(Pango\Attribute\AttributeIterator)#%d (0) {
}
object(Pango\Attribute\AttributeIterator)#%d (0) {
}
