--TEST--
Pango\Attribute\Family read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Family;

$family = new Family("Arial");

var_dump($family->value);
var_dump($family->startIndex);
var_dump($family->endIndex);
?>
--EXPECT--
string(5) "Arial"
int(0)
int(4294967295)
