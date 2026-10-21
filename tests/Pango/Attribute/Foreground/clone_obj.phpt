--TEST--
Pango\Attribute\ForegroundAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\ForegroundAttribute;

$foreground = new Foreground(new Pango\Color(1024, 2048, 4096));
var_dump($foreground->color->red);

$copy = clone $foreground;
var_dump($copy->color->red);
?>
--EXPECT--
int(1024)
int(1024)
