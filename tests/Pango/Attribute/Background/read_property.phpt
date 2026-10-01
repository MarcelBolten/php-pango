--TEST--
Pango\Attribute\Background read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Background;

$background = new Background(new Pango\Color(1024, 2048, 4096));

var_dump($background->color->red);
var_dump($background->startIndex);
var_dump($background->endIndex);
?>
--EXPECT--
int(1024)
int(0)
int(4294967295)
