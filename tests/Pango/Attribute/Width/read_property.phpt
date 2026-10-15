--TEST--
Pango\Attribute\Width read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\Width;

$width = new Width(Pango\Width::Expanded);

var_dump($width->value);
var_dump($width->startIndex);
var_dump($width->endIndex);
?>
--EXPECT--
enum(Pango\Width::Expanded)
int(0)
int(4294967295)
