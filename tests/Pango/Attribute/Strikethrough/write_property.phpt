--TEST--
Pango\Attribute\Strikethrough object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Strikethrough;

$strikethrough = new Strikethrough(true);
$strikethrough->value = false;
$strikethrough->startIndex = 13;
$strikethrough->endIndex = 42;

var_dump($strikethrough->value);
var_dump($strikethrough->startIndex);
var_dump($strikethrough->endIndex);
?>
--EXPECT--
bool(false)
int(13)
int(42)
