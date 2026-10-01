--TEST--
Pango\Color object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Color;

$color = new Color(1024, 2048, 4096);

$color->red = 1;
$color->green = 2;
$color->blue = 3;

var_dump($color->red);
var_dump($color->green);
var_dump($color->blue);
?>
--EXPECT--
int(1)
int(2)
int(3)
