--TEST--
Pango\Attribute\LineHeight read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\LineHeight;

$LineHeight = new LineHeight(5.2);

var_dump($LineHeight->value);
var_dump($LineHeight->startIndex);
var_dump($LineHeight->endIndex);
?>
--EXPECT--
float(5.2)
int(0)
int(4294967295)
