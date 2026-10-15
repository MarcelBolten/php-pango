--TEST--
Pango\Matrix->getGravity()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Matrix;

$gravities = [
    'south' => [ 1,  0,  0,  1],
    'west' =>  [ 0, -1,  1,  0],
    'north' => [-1,  0,  0, -1],
    'east' =>  [ 0,  1, -1,  0],
];

foreach ($gravities as $elements) {
    var_dump((new Matrix(...$elements))->getGravity());
}

try {
    (new Matrix())->getGravity(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
enum(Pango\Gravity::South)
enum(Pango\Gravity::West)
enum(Pango\Gravity::North)
enum(Pango\Gravity::East)
Pango\Matrix::getGravity() expects exactly 0 arguments, 1 given
