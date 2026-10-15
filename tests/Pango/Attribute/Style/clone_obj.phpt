--TEST--
Pango\Attribute\Style clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\Style;

$style = new Style(Pango\Style::Italic);
var_dump($style->value);

$copy = clone $style;
var_dump($copy->value);
?>
--EXPECT--
enum(Pango\Style::Italic)
enum(Pango\Style::Italic)
