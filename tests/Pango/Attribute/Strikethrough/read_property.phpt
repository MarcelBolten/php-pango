--TEST--
Pango\Attribute\Strikethrough read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Strikethrough;

$strikethrough = new Strikethrough(true);

var_dump($strikethrough->value);
var_dump($strikethrough->startIndex);
var_dump($strikethrough->endIndex);
?>
--EXPECT--
bool(true)
int(0)
int(4294967295)
