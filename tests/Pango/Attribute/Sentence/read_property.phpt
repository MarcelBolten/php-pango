--TEST--
Pango\Attribute\SentenceAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\SentenceAttribute;

$sentence = new SentenceAttribute();

var_dump($sentence->startIndex);
var_dump($sentence->endIndex);
?>
--EXPECT--
int(0)
int(4294967295)
