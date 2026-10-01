--TEST--
Pango\Attribute\AttributeIterator clone object handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
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
object(Pango\Attribute\AttributeList)#%d (0) {
}
object(Pango\Attribute\AttributeIterator)#%d (0) {
}
object(Pango\Attribute\AttributeIterator)#%d (0) {
}
