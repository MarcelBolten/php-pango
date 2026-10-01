--TEST--
Pango\Attribute\Variant read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Variant;

$variant = new Variant(Pango\Variant::SmallCaps);

var_dump($variant->value);
var_dump($variant->startIndex);
var_dump($variant->endIndex);
?>
--EXPECT--
enum(Pango\Variant::SmallCaps)
int(0)
int(4294967295)
