--TEST--
Pango\Attribute\TextTransformAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\TextTransformAttribute;

$textTransform = new TextTransform(Pango\TextTransform::Lowercase);
var_dump($textTransform->value);

$copy = clone $textTransform;
var_dump($copy->value);
?>
--EXPECT--
enum(Pango\TextTransform::Lowercase)
enum(Pango\TextTransform::Lowercase)
