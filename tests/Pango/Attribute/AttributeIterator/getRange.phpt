--TEST--
Pango\Attribute\AttributeIterator::getRange()
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
var_dump($attrIter->getRange());

try {
    $attrIter->getRange(123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\AttributeList)#%d (0) {
}
object(Pango\Attribute\AttributeIterator)#%d (0) {
}
array(2) {
  ["start"]=>
  int(0)
  ["end"]=>
  int(10)
}
Pango\Attribute\AttributeIterator::getRange() expects exactly 0 arguments, 1 given
