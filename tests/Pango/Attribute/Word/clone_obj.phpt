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
var_dump($word);
var_dump(clone $word);
?>
--EXPECT--
object(Pango\Attribute\Word)#1 (2) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
}
object(Pango\Attribute\Word)#2 (2) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
}
