--TEST--
Pango\Coverage::__construct()
--EXTENSIONS--
pango
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
