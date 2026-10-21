--TEST--
Pango\Attribute\WeightAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\WeightAttribute;

$weight = new Weight(Pango\Weight::Bold);

var_dump($weight->value);
var_dump($weight->startIndex);
var_dump($weight->endIndex);
?>
--EXPECT--
enum(Pango\Weight::Bold)
int(0)
int(4294967295)
