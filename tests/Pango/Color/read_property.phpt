--TEST--
Pango\Color read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$color = new Pango\Color(1024, 2048, 4096);

var_dump($color->red);
var_dump($color->green);
var_dump($color->blue);
?>
--EXPECT--
int(1024)
int(2048)
int(4096)
