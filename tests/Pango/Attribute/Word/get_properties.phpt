--TEST--
Pango\Attribute\WordAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\WordAttribute;

$word = new WordAttribute();
var_dump($word);
print_r($word);
?>
--EXPECTF--
object(Pango\Attribute\WordAttribute)#%d (2) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
}
Pango\Attribute\WordAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
)