--TEST--
Pango\Attribute\BaselineShift clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\BaselineShift;

$baselineShift = new BaselineShift(Pango\BaselineShift::Superscript);
var_dump($baselineShift->value);

$copy = clone $baselineShift;
$copy->value = Pango\BaselineShift::Subscript;

var_dump($copy->value);
?>
--EXPECT--
enum(Pango\BaselineShift::Superscript)
enum(Pango\BaselineShift::Subscript)
