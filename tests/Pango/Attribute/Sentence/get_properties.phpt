--TEST--
Pango\Attribute\Sentence get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Sentence;

$sentence = new Sentence();
var_dump($sentence);
print_r($sentence);
?>
--EXPECTF--
object(Pango\Attribute\Sentence)#%d (2) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
}
Pango\Attribute\Sentence Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
)