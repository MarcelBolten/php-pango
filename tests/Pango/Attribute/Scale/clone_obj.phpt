--TEST--
Pango\Attribute\Scale clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Scale;

$scale = new Scale(5.2);
var_dump($scale->value);

$copy = clone $scale;
var_dump($copy->value);
?>
--EXPECT--
float(5.2)
float(5.2)
