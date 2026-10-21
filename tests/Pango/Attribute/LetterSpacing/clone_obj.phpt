--TEST--
Pango\Attribute\LetterSpacingAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\LetterSpacingAttribute;

$letterSpacing = new LetterSpacing(5);
var_dump($letterSpacing->value);

$copy = clone $letterSpacing;
var_dump($copy->value);
?>
--EXPECT--
int(5)
int(5)
