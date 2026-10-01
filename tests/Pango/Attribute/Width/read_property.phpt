--TEST--
Pango\Attribute\Width read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Width;

$width = new Width(10240);

var_dump($width->value);
var_dump($width->startIndex);
var_dump($width->endIndex);
?>
--EXPECT--
int(10240)
int(0)
int(4294967295)
