--TEST--
Pango\Attribute\ForegroundAlpha clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\ForegroundAlpha;

$foregroundAlpha = new ForegroundAlpha(5);
var_dump($foregroundAlpha->value);

$copy = clone $foregroundAlpha;
$copy->value = 9;

var_dump($copy->value);
?>
--EXPECT--
int(5)
int(9)
