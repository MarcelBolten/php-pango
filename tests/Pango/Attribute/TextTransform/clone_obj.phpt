--TEST--
Pango\Attribute\TextTransform clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\TextTransform;

$textTransform = new TextTransform(Pango\TextTransform::Lowercase);
var_dump($textTransform->value);

$copy = clone $textTransform;
var_dump($copy->value);
?>
--EXPECT--
enum(Pango\TextTransform::Lowercase)
enum(Pango\TextTransform::Lowercase)
