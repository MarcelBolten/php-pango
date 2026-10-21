--TEST--
Pango\Attribute\AbsoluteSizeAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\AbsoluteSizeAttribute;

$absoluteSize = new AbsoluteSizeAttribute(5);

var_dump($absoluteSize->value);
var_dump($absoluteSize->startIndex);
var_dump($absoluteSize->endIndex);
?>
--EXPECT--
int(5)
int(0)
int(4294967295)
