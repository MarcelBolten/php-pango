--TEST--
Pango\Attribute\Style read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\Style;

$style = new Style(Pango\Style::Italic);

var_dump($style->value);
var_dump($style->startIndex);
var_dump($style->endIndex);
?>
--EXPECT--
enum(Pango\Style::Italic)
int(0)
int(4294967295)
