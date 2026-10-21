--TEST--
Pango\Attribute\VariantAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\VariantAttribute;

$variant = new Variant(Pango\Variant::SmallCaps);
var_dump($variant->value);

$copy = clone $variant;
var_dump($copy->value);
?>
--EXPECT--
enum(Pango\Variant::SmallCaps)
enum(Pango\Variant::SmallCaps)
