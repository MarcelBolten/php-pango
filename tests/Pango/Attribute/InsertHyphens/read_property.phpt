--TEST--
Pango\Attribute\InsertHyphens read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\InsertHyphens;

$insertHyphens = new InsertHyphens(true);

var_dump($insertHyphens->value);
var_dump($insertHyphens->startIndex);
var_dump($insertHyphens->endIndex);
?>
--EXPECT--
bool(true)
int(0)
int(4294967295)
