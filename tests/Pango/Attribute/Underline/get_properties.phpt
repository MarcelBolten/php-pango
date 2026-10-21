--TEST--
Pango\Attribute\UnderlineAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\UnderlineAttribute;

$underline = new Underline(Pango\Underline::Double);
var_dump($underline);
print_r($underline);
?>
--EXPECTF--
object(Pango\Attribute\UnderlineAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Underline::Double)
}
Pango\Attribute\UnderlineAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\Underline Enum:int
        (
            [name] => Double
            [value] => 2
        )

)
