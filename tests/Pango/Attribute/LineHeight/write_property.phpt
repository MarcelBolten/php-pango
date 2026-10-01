--TEST--
Pango\Attribute\LineHeight object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\LineHeight;

$LineHeight = new LineHeight(5.2);
$LineHeight->value = 10.5;
$LineHeight->startIndex = 13;
$LineHeight->endIndex = 42;

var_dump($LineHeight->value);
var_dump($LineHeight->startIndex);
var_dump($LineHeight->endIndex);
?>
--EXPECT--
float(10.5)
int(13)
int(42)
