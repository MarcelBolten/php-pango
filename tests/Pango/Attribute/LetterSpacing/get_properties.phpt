--TEST--
Pango\Attribute\LetterSpacingAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\LetterSpacingAttribute;

$letterSpacing = new LetterSpacing(5);
var_dump($letterSpacing);
print_r($letterSpacing);
?>
--EXPECTF--
object(Pango\Attribute\LetterSpacingAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(5)
}
Pango\Attribute\LetterSpacingAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 5
)