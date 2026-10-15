--TEST--
Pango\Attribute\ForegroundAlpha clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\ForegroundAlpha;

$foregroundAlpha = new ForegroundAlpha(5);
var_dump($foregroundAlpha->value);

$copy = clone $foregroundAlpha;
var_dump($copy->value);
?>
--EXPECT--
int(5)
int(5)
