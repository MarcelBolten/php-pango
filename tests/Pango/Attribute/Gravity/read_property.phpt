--TEST--
Pango\Attribute\Gravity read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Gravity;

$gravity = new Gravity(Pango\Gravity::North);

var_dump($gravity->value);
var_dump($gravity->startIndex);
var_dump($gravity->endIndex);
?>
--EXPECT--
enum(Pango\Gravity::North)
int(0)
int(4294967295)
