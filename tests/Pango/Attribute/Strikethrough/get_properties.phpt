--TEST--
Pango\Attribute\StrikethroughAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\StrikethroughAttribute;

$strikethrough = new Strikethrough(true);
var_dump($strikethrough);
print_r($strikethrough);
?>
--EXPECTF--
object(Pango\Attribute\StrikethroughAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  bool(true)
}
Pango\Attribute\StrikethroughAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 1
)