--TEST--
Pango\Attribute\Weight read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Weight;

$weight = new Weight(Pango\Weight::Bold);

var_dump($weight->value);
var_dump($weight->startIndex);
var_dump($weight->endIndex);
?>
--EXPECT--
enum(Pango\Weight::Bold)
int(0)
int(4294967295)
