--TEST--
Pango\Attribute\Word::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Word;

$word = new Word();
var_dump($word);

try {
    new Word(1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\Word)#%d (2) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
}
Pango\Attribute\Word::__construct() expects at most 2 arguments, 3 given
