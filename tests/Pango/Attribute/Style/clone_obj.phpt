--TEST--
Pango\Attribute\StyleAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\StyleAttribute;

$style = new StyleAttribute(Pango\Style::Italic);
var_dump($style->value);

$copy = clone $style;
var_dump($copy->value);
?>
--EXPECT--
enum(Pango\Style::Italic)
enum(Pango\Style::Italic)
