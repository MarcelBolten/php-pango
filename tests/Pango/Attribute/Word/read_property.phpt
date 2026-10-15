--TEST--
Pango\Attribute\Word read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\Word;

$word = new Word();

var_dump($word->startIndex);
var_dump($word->endIndex);
?>
--EXPECT--
int(0)
int(4294967295)
