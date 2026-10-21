--TEST--
Pango\Attribute\FontScaleAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\FontScaleAttribute;

$fontScale = new FontScale(Pango\FontScale::SmallCaps);
var_dump($fontScale->value);

$copy = clone $fontScale;
var_dump($copy->value);
?>
--EXPECT--
enum(Pango\FontScale::SmallCaps)
enum(Pango\FontScale::SmallCaps)
