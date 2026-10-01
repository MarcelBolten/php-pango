--TEST--
Pango\Coverage::get()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Coverage;

$coverage = new Coverage();
var_dump($coverage);
var_dump($coverage->get(65));

try {
    $coverage->get();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $coverage->get(1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $coverage->get(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
object(Pango\Coverage)#1 (0) {
}
enum(Pango\CoverageLevel::None)
Pango\Coverage::get() expects exactly 1 argument, 0 given
Pango\Coverage::get() expects exactly 1 argument, 2 given
Pango\Coverage::get(): Argument #1 ($index) must be of type int, array given
