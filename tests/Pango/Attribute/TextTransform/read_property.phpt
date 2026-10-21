--TEST--
Pango\Attribute\TextTransformAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\TextTransformAttribute;

$textTransform = new TextTransform(Pango\TextTransform::Lowercase);

var_dump($textTransform->value);
var_dump($textTransform->startIndex);
var_dump($textTransform->endIndex);
?>
--EXPECT--
enum(Pango\TextTransform::Lowercase)
int(0)
int(4294967295)
