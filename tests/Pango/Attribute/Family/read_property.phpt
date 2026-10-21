--TEST--
Pango\Attribute\FamilyAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\FamilyAttribute;

$family = new Family("Arial");

var_dump($family->value);
var_dump($family->startIndex);
var_dump($family->endIndex);
?>
--EXPECT--
string(5) "Arial"
int(0)
int(4294967295)
