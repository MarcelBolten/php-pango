--TEST--
Pango\Attribute\BaselineShiftAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\BaselineShiftAttribute;

$baselineShift = new BaselineShiftAttribute(Pango\BaselineShift::Superscript);
var_dump($baselineShift->value);

$copy = clone $baselineShift;
var_dump($copy->value);
?>
--EXPECT--
enum(Pango\BaselineShift::Superscript)
enum(Pango\BaselineShift::Superscript)
