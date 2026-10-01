--TEST--
Pango\Attribute\Scale object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Scale;

$scale = new Scale(5.2);
$scale->value = 10.5;
$scale->startIndex = 13;
$scale->endIndex = 42;

var_dump($scale->value);
var_dump($scale->startIndex);
var_dump($scale->endIndex);
?>
--EXPECT--
float(10.5)
int(13)
int(42)
