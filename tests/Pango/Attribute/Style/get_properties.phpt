--TEST--
Pango\Attribute\Style get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Style;

$style = new Style(Pango\Style::Italic);
var_dump($style);
print_r($style);
?>
--EXPECTF--
object(Pango\Attribute\Style)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Style::Italic)
}
Pango\Attribute\Style Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\Style Enum:int
        (
            [name] => Italic
            [value] => 2
        )

)
