--TEST--
Pango\Attribute\ShowAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\ShowAttribute;

$show = new ShowAttribute(ShowAttribute::NONE);

var_dump($show->value);
var_dump($show->startIndex);
var_dump($show->endIndex);
?>
--EXPECT--
int(0)
int(0)
int(4294967295)
