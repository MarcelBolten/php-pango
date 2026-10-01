--TEST--
Pango\Attribute\UnderlineColor clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\UnderlineColor;

$underlineColor = new UnderlineColor(new Pango\Color(1024, 2048, 4096));
var_dump($underlineColor->color->red);

$copy = clone $underlineColor;
$copy->color = new Pango\Color(512, 1024, 2048);

var_dump($copy->color->red);
?>
--EXPECT--
int(1024)
int(512)
