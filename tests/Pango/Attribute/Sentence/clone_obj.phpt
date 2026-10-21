--TEST--
Pango\Attribute\SentenceAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\SentenceAttribute;

$sentence = new Sentence();
var_dump($sentence->startIndex);

$copy = clone $sentence;
var_dump($copy->startIndex);
?>
--EXPECT--
int(0)
int(0)
