--TEST--
Pango\Attribute\BackgroundAlpha object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\BackgroundAlpha;

$backgroundAlpha = new BackgroundAlpha(5);
$backgroundAlpha->value = 10;
$backgroundAlpha->startIndex = 13;
$backgroundAlpha->endIndex = 42;

var_dump($backgroundAlpha->value);
var_dump($backgroundAlpha->startIndex);
var_dump($backgroundAlpha->endIndex);
?>
--EXPECT--
int(10)
int(13)
int(42)
