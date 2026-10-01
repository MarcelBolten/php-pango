--TEST--
Pango\Attribute\LetterSpacing clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\LetterSpacing;

$letterSpacing = new LetterSpacing(5);
var_dump($letterSpacing->value);

$copy = clone $letterSpacing;
$copy->value = 9;

var_dump($copy->value);
?>
--EXPECT--
int(5)
int(9)
