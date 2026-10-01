--TEST--
Pango\Attribute\Size object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Size;

$size = new Size(5);
$size->value = 10;
$size->startIndex = 13;
$size->endIndex = 42;

var_dump($size->value);
var_dump($size->startIndex);
var_dump($size->endIndex);
?>
--EXPECT--
int(10)
int(13)
int(42)
