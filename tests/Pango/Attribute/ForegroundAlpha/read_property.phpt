--TEST--
Pango\Attribute\ForegroundAlpha read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\ForegroundAlpha;

$foregroundAlpha = new ForegroundAlpha(5);

var_dump($foregroundAlpha->value);
var_dump($foregroundAlpha->startIndex);
var_dump($foregroundAlpha->endIndex);
?>
--EXPECT--
int(5)
int(0)
int(4294967295)
