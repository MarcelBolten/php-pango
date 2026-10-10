--TEST--
Pango\Attribute\Stretch clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Stretch;

$stretch = new Stretch(Pango\Stretch::Expanded);
var_dump($stretch->value);

$copy = clone $stretch;
var_dump($copy->value);
?>
--EXPECT--
enum(Pango\Stretch::Expanded)
enum(Pango\Stretch::Expanded)
