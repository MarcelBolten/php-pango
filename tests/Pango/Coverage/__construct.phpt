--TEST--
Pango\Coverage::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Coverage;

$coverage = new Coverage();
var_dump($coverage);

try {
    new Coverage(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Coverage)#1 (0) {
}
Pango\Coverage::__construct() expects exactly 0 arguments, 1 given
