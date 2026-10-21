--TEST--
Pango\Attribute\BackgroundAlphaAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\BackgroundAlphaAttribute;

$backgroundAlpha = new BackgroundAlpha(5);
var_dump($backgroundAlpha->value);

$copy = clone $backgroundAlpha;
var_dump($copy->value);
?>
--EXPECT--
int(5)
int(5)
