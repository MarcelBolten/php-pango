--TEST--
Pango\Attribute\UnderlineColor read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\UnderlineColor;

$underlineColor = new UnderlineColor(new Pango\Color(1024, 2048, 4096));

var_dump($underlineColor->color->red);
var_dump($underlineColor->startIndex);
var_dump($underlineColor->endIndex);
?>
--EXPECT--
int(1024)
int(0)
int(4294967295)
