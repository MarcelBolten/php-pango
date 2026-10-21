--TEST--
Pango\Attribute\WeightAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\WeightAttribute;

$weight = new Weight(Pango\Weight::Bold);
var_dump($weight->value);

$copy = clone $weight;
var_dump($copy->value);
?>
--EXPECT--
enum(Pango\Weight::Bold)
enum(Pango\Weight::Bold)
