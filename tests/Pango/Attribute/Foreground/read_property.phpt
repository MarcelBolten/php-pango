--TEST--
Pango\Attribute\Foreground read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Foreground;

$foreground = new Foreground(new Pango\Color(1024, 2048, 4096));

var_dump($foreground->color->red);
var_dump($foreground->startIndex);
var_dump($foreground->endIndex);
?>
--EXPECT--
int(1024)
int(0)
int(4294967295)
