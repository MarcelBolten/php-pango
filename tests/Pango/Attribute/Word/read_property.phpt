--TEST--
Pango\Attribute\WordAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\WordAttribute;

$word = new WordAttribute();

var_dump($word->startIndex);
var_dump($word->endIndex);
?>
--EXPECT--
int(0)
int(4294967295)
