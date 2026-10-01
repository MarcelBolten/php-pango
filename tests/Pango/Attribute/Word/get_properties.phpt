--TEST--
Pango\Attribute\Word get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Word;

$word = new Word();
var_dump($word);
print_r($word);
?>
--EXPECTF--
object(Pango\Attribute\Word)#%d (2) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
}
Pango\Attribute\Word Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
)