--TEST--
Pango\Attribute\StrikethroughColor read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\StrikethroughColor;

$strikethroughColor = new StrikethroughColor(new Pango\Color(1024, 2048, 4096));

var_dump($strikethroughColor->color->red);
var_dump($strikethroughColor->startIndex);
var_dump($strikethroughColor->endIndex);
?>
--EXPECT--
int(1024)
int(0)
int(4294967295)
