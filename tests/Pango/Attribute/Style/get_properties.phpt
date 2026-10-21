--TEST--
Pango\Attribute\StyleAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\StyleAttribute;

$style = new StyleAttribute(Pango\Style::Italic);
var_dump($style);
print_r($style);
?>
--EXPECTF--
object(Pango\Attribute\StyleAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Style::Italic)
}
Pango\Attribute\StyleAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\Style Enum:int
        (
            [name] => Italic
            [value] => 2
        )

)
