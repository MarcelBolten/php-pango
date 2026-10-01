--TEST--
Pango\Coverage::set()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Coverage;
use Pango\CoverageLevel;

$coverage = new Coverage();
var_dump($coverage);
var_dump($coverage->get(65));
$coverage->set(65, CoverageLevel::Exact);
var_dump($coverage->get(65));

try {
    $coverage->set();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $coverage->set(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $coverage->set(1, CoverageLevel::None, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $coverage->set(array(), CoverageLevel::None);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $coverage->set(1, array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
object(Pango\Coverage)#1 (0) {
}
enum(Pango\CoverageLevel::None)
enum(Pango\CoverageLevel::Exact)
Pango\Coverage::set() expects exactly 2 arguments, 0 given
Pango\Coverage::set() expects exactly 2 arguments, 1 given
Pango\Coverage::set() expects exactly 2 arguments, 3 given
Pango\Coverage::set(): Argument #1 ($index) must be of type int, array given
Pango\Coverage::set(): Argument #2 ($level) must be of type Pango\CoverageLevel, array given
