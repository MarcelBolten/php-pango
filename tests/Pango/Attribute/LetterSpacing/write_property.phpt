--TEST--
Pango\Attribute\LetterSpacing object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\LetterSpacing;

$letterSpacing = new LetterSpacing(5);
$letterSpacing->value = 10;
$letterSpacing->startIndex = 13;
$letterSpacing->endIndex = 42;

var_dump($letterSpacing->value);
var_dump($letterSpacing->startIndex);
var_dump($letterSpacing->endIndex);
?>
--EXPECT--
int(10)
int(13)
int(42)
