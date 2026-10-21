--TEST--
Pango\Attribute\ForegroundAlphaAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\ForegroundAlphaAttribute;

$foregroundAlpha = new ForegroundAlpha(5);
var_dump($foregroundAlpha->value);

$copy = clone $foregroundAlpha;
var_dump($copy->value);
?>
--EXPECT--
int(5)
int(5)
