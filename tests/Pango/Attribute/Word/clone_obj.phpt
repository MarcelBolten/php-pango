--TEST--
Pango\Attribute\WordAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\WordAttribute;

$word = new WordAttribute();
var_dump($word);
var_dump(clone $word);
?>
--EXPECT--
object(Pango\Attribute\WordAttribute)#1 (2) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
}
object(Pango\Attribute\WordAttribute)#2 (2) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
}
