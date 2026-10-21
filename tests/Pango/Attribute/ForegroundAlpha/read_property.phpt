--TEST--
Pango\Attribute\ForegroundAlphaAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\ForegroundAlphaAttribute;

$foregroundAlpha = new ForegroundAlpha(5);

var_dump($foregroundAlpha->value);
var_dump($foregroundAlpha->startIndex);
var_dump($foregroundAlpha->endIndex);
?>
--EXPECT--
int(5)
int(0)
int(4294967295)
