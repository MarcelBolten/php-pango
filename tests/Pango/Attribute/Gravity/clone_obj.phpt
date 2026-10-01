--TEST--
Pango\Attribute\Gravity clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Gravity;

$gravity = new Gravity(Pango\Gravity::North);
var_dump($gravity->value);

$copy = clone $gravity;
$copy->value = Pango\Gravity::South;

var_dump($copy->value);
?>
--EXPECT--
enum(Pango\Gravity::North)
enum(Pango\Gravity::South)
