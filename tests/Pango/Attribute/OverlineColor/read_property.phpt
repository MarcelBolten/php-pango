--TEST--
Pango\Attribute\OverlineColor read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\OverlineColor;

$overlineColor = new OverlineColor(new Pango\Color(1024, 2048, 4096));

var_dump($overlineColor->color->red);
var_dump($overlineColor->startIndex);
var_dump($overlineColor->endIndex);
?>
--EXPECT--
int(1024)
int(0)
int(4294967295)
