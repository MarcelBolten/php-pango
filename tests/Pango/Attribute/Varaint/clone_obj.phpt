--TEST--
Pango\Attribute\Variant clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Variant;

$variant = new Variant(Pango\Variant::SmallCaps);
var_dump($variant->value);

$copy = clone $variant;
$copy->value = Pango\Variant::TitleCaps;

var_dump($copy->value);
?>
--EXPECT--
enum(Pango\Variant::SmallCaps)
enum(Pango\Variant::TitleCaps)
