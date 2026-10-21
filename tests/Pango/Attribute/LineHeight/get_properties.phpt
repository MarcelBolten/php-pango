--TEST--
Pango\Attribute\LineHeightAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\LineHeightAttribute;

$LineHeight = new LineHeightAttribute(5.2);
var_dump($LineHeight);
print_r($LineHeight);
?>
--EXPECTF--
object(Pango\Attribute\LineHeightAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  float(5.2)
}
Pango\Attribute\LineHeightAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 5.2
)