--TEST--
Pango\Attribute\VariantAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\VariantAttribute;

$variant = new VariantAttribute(Pango\Variant::SmallCaps);

var_dump($variant->value);
var_dump($variant->startIndex);
var_dump($variant->endIndex);
?>
--EXPECT--
enum(Pango\Variant::SmallCaps)
int(0)
int(4294967295)
