--TEST--
Pango\Attribute\Word object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Word;

$word = new Word();
$word->startIndex = 13;
$word->endIndex = 42;

var_dump($word->startIndex);
var_dump($word->endIndex);
?>
--EXPECT--
int(13)
int(42)
