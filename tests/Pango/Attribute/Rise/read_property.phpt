--TEST--
Pango\Attribute\RiseAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\RiseAttribute;

$rise = new RiseAttribute(5);

var_dump($rise->value);
var_dump($rise->startIndex);
var_dump($rise->endIndex);
?>
--EXPECT--
int(5)
int(0)
int(4294967295)
