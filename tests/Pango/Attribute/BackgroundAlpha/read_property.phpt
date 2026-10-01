--TEST--
Pango\Attribute\BackgroundAlpha read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\BackgroundAlpha;

$backgroundAlpha = new BackgroundAlpha(5);

var_dump($backgroundAlpha->value);
var_dump($backgroundAlpha->startIndex);
var_dump($backgroundAlpha->endIndex);
?>
--EXPECT--
int(5)
int(0)
int(4294967295)
