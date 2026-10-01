--TEST--
Pango\Attribute\AbsoluteLineHeight read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AbsoluteLineHeight;

$absoluteLineHeight = new AbsoluteLineHeight(5);

var_dump($absoluteLineHeight->value);
var_dump($absoluteLineHeight->startIndex);
var_dump($absoluteLineHeight->endIndex);
?>
--EXPECT--
int(5)
int(0)
int(4294967295)
