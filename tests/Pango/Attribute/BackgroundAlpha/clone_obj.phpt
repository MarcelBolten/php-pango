--TEST--
Pango\Attribute\BackgroundAlpha clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\BackgroundAlpha;

$backgroundAlpha = new BackgroundAlpha(5);
var_dump($backgroundAlpha->value);

$copy = clone $backgroundAlpha;
$copy->value = 9;

var_dump($copy->value);
?>
--EXPECT--
int(5)
int(9)
