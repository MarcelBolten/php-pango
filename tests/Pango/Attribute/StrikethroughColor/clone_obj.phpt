--TEST--
Pango\Attribute\StrikethroughColor clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\StrikethroughColor;

$strikethroughColor = new StrikethroughColor(new Pango\Color(1024, 2048, 4096));
var_dump($strikethroughColor->color->red);

$copy = clone $strikethroughColor;
$copy->color = new Pango\Color(512, 1024, 2048);

var_dump($copy->color->red);
?>
--EXPECT--
int(1024)
int(512)
