--TEST--
Pango\Rectangle read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
$rectangle = new Pango\Rectangle(4, 3, 2, 1);

var_dump($rectangle->x);
var_dump($rectangle->y);
var_dump($rectangle->width);
var_dump($rectangle->height);
var_dump($rectangle->ascent);
var_dump($rectangle->descent);
var_dump($rectangle->leftBearing);
var_dump($rectangle->rightBearing);
?>
--EXPECT--
int(4)
int(3)
int(2)
int(1)
int(-3)
int(4)
int(4)
int(6)
