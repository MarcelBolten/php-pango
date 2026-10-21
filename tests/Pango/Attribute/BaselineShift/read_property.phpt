--TEST--
Pango\Attribute\BaselineShiftAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\BaselineShiftAttribute;

$baselineShift = new BaselineShiftAttribute(Pango\BaselineShift::Superscript);

var_dump($baselineShift->value);
var_dump($baselineShift->startIndex);
var_dump($baselineShift->endIndex);
?>
--EXPECT--
enum(Pango\BaselineShift::Superscript)
int(0)
int(4294967295)
