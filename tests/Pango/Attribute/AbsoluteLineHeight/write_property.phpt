--TEST--
Pango\Attribute\AbsoluteLineHeight object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AbsoluteLineHeight;

$absoluteLineHeight = new AbsoluteLineHeight(5);
$absoluteLineHeight->value = 10;
$absoluteLineHeight->startIndex = 13;
$absoluteLineHeight->endIndex = 42;

var_dump($absoluteLineHeight->value);
var_dump($absoluteLineHeight->startIndex);
var_dump($absoluteLineHeight->endIndex);
?>
--EXPECT--
int(10)
int(13)
int(42)
