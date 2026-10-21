--TEST--
Pango\Attribute\BackgroundAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\BackgroundAttribute;

$background = new BackgroundAttribute(new Pango\Color(1024, 2048, 4096));

var_dump($background->color->red);
var_dump($background->startIndex);
var_dump($background->endIndex);
?>
--EXPECT--
int(1024)
int(0)
int(4294967295)
