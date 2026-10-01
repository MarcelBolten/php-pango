--TEST--
Pango\Attribute\Width object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Width;

$width = new Width(10240);
$width->value = 20480;
$width->startIndex = 13;
$width->endIndex = 42;

var_dump($width->value);
var_dump($width->startIndex);
var_dump($width->endIndex);
?>
--EXPECT--
int(20480)
int(13)
int(42)
