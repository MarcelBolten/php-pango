--TEST--
Pango\Attribute\LetterSpacingAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\LetterSpacingAttribute;

$letterSpacing = new LetterSpacingAttribute(5);

var_dump($letterSpacing->value);
var_dump($letterSpacing->startIndex);
var_dump($letterSpacing->endIndex);
?>
--EXPECT--
int(5)
int(0)
int(4294967295)
