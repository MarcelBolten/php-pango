--TEST--
Pango\Attribute\Weight clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Weight;

$weight = new Weight(Pango\Weight::Bold);
var_dump($weight->value);

$copy = clone $weight;
var_dump($copy->value);
?>
--EXPECT--
enum(Pango\Weight::Bold)
enum(Pango\Weight::Bold)
