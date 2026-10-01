--TEST--
Pango\Attribute\Size read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Size;

$size = new Size(5);

var_dump($size->value);
var_dump($size->startIndex);
var_dump($size->endIndex);
?>
--EXPECT--
int(5)
int(0)
int(4294967295)
