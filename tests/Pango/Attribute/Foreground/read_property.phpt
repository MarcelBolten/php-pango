--TEST--
Pango\Attribute\ForegroundAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\ForegroundAttribute;

$foreground = new ForegroundAttribute(new Pango\Color(1024, 2048, 4096));

var_dump($foreground->color->red);
var_dump($foreground->startIndex);
var_dump($foreground->endIndex);
?>
--EXPECT--
int(1024)
int(0)
int(4294967295)
