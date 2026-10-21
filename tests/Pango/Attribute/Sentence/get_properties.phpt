--TEST--
Pango\Attribute\SentenceAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\SentenceAttribute;

$sentence = new Sentence();
var_dump($sentence);
print_r($sentence);
?>
--EXPECTF--
object(Pango\Attribute\SentenceAttribute)#%d (2) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
}
Pango\Attribute\SentenceAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
)