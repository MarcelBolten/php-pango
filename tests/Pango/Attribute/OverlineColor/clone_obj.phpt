--TEST--
Pango\Attribute\OverlineColor clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\OverlineColor;

$overlineColor = new OverlineColor(new Pango\Color(1024, 2048, 4096));
var_dump($overlineColor->color->red);

$copy = clone $overlineColor;
$copy->color = new Pango\Color(512, 1024, 2048);

var_dump($copy->color->red);
?>
--EXPECT--
int(1024)
int(512)
