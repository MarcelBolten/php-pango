--TEST--
Pango\Attribute\AbsoluteLineHeight clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AbsoluteLineHeight;

$absoluteLineHeight = new AbsoluteLineHeight(5);
var_dump($absoluteLineHeight->value);

$copy = clone $absoluteLineHeight;
$copy->value = 9;

var_dump($copy->value);
?>
--EXPECT--
int(5)
int(9)
