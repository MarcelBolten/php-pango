--TEST--
Pango\Attribute\Overline read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Overline;

$overline = new Overline(Pango\Overline::Single);

var_dump($overline->value);
var_dump($overline->startIndex);
var_dump($overline->endIndex);
?>
--EXPECT--
enum(Pango\Overline::Single)
int(0)
int(4294967295)
