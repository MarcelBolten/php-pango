--TEST--
Pango\Attribute\Word clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Word;

$word = new Word();
var_dump($word->startIndex);

$copy = clone $word;
$copy->startIndex = 9;

var_dump($copy->startIndex);
?>
--EXPECT--
int(0)
int(9)
