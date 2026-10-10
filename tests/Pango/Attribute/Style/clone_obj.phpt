--TEST--
Pango\Attribute\Style clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
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
