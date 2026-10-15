--TEST--
Pango\Attribute\Sentence read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\Sentence;

$sentence = new Sentence();

var_dump($sentence->startIndex);
var_dump($sentence->endIndex);
?>
--EXPECT--
int(0)
int(4294967295)
