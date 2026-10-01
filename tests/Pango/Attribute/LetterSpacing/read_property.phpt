--TEST--
Pango\Attribute\LetterSpacing read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\LetterSpacing;

$letterSpacing = new LetterSpacing(5);

var_dump($letterSpacing->value);
var_dump($letterSpacing->startIndex);
var_dump($letterSpacing->endIndex);
?>
--EXPECT--
int(5)
int(0)
int(4294967295)
