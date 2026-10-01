--TEST--
Pango\Attribute\ForegroundAlpha object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\ForegroundAlpha;

$foregroundAlpha = new ForegroundAlpha(5);
$foregroundAlpha->value = 10;
$foregroundAlpha->startIndex = 13;
$foregroundAlpha->endIndex = 42;

var_dump($foregroundAlpha->value);
var_dump($foregroundAlpha->startIndex);
var_dump($foregroundAlpha->endIndex);
?>
--EXPECT--
int(10)
int(13)
int(42)
