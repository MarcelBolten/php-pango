--TEST--
Pango\Attribute\LineHeight clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\LineHeight;

$LineHeight = new LineHeight(5.2);
var_dump($LineHeight->value);

$copy = clone $LineHeight;
var_dump($copy->value);
?>
--EXPECT--
float(5.2)
float(5.2)
