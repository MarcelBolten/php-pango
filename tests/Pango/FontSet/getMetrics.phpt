--TEST--
Pango\FontSet::getMetrics()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\FontSetSimple;
use Pango\Language;

$fss = new FontSetSimple(new Language("en"));
var_dump($fss);
var_dump($fss->getMetrics());

try {
    $fss->getMetrics(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontSetSimple)#%d (1) {
  ["size"]=>
  int(0)
}
object(Pango\FontMetrics)#%d (0) {
}
Pango\FontSet::getMetrics() expects exactly 0 arguments, 1 given
