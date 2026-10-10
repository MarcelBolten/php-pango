--TEST--
Pango\Attribute\Size clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Size;

$size = new Size(5);
var_dump($size->value);

$copy = clone $size;
var_dump($copy->value);
?>
--EXPECT--
int(5)
int(5)
