--TEST--
Pango\Attribute\LetterSpacing clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\LetterSpacing;

$letterSpacing = new LetterSpacing(5);
var_dump($letterSpacing->value);

$copy = clone $letterSpacing;
var_dump($copy->value);
?>
--EXPECT--
int(5)
int(5)
