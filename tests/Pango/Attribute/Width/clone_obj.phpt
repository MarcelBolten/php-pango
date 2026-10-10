--TEST--
Pango\Attribute\Width clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Width;

$width = new Width(10240);
var_dump($width->value);

$copy = clone $width;
var_dump($copy->value);
?>
--EXPECT--
int(10240)
int(10240)
