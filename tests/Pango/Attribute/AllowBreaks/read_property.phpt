--TEST--
Pango\Attribute\AllowBreaks read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\AllowBreaks;

$allowBreaks = new AllowBreaks(true);

var_dump($allowBreaks->value);
var_dump($allowBreaks->startIndex);
var_dump($allowBreaks->endIndex);
?>
--EXPECT--
bool(true)
int(0)
int(4294967295)
