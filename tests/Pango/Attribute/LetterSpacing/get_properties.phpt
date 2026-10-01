--TEST--
Pango\Attribute\LetterSpacing get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\LetterSpacing;

$letterSpacing = new LetterSpacing(5);
var_dump($letterSpacing);
print_r($letterSpacing);
?>
--EXPECTF--
object(Pango\Attribute\LetterSpacing)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(5)
}
Pango\Attribute\LetterSpacing Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 5
)