--TEST--
Pango\Attribute\Stretch read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Stretch;

$stretch = new Stretch(Pango\Stretch::Expanded);

var_dump($stretch->value);
var_dump($stretch->startIndex);
var_dump($stretch->endIndex);
?>
--EXPECT--
enum(Pango\Stretch::Expanded)
int(0)
int(4294967295)
