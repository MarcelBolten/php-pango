--TEST--
Pango\Attribute\AttributeIterator::next()
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
var_dump($attrIter->next()); // advance to 10-MAX_INT
var_dump($attrIter->next()); // no more advance

try {
    $attrIter->next(123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\AttributeList)#%d (0) {
}
object(Pango\Attribute\AttributeIterator)#%d (0) {
}
bool(true)
bool(false)
Pango\Attribute\AttributeIterator::next() expects exactly 0 arguments, 1 given
