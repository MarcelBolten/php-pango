--TEST--
Pango\Attribute\AllowBreaksAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\AllowBreaksAttribute;

$allowBreaks = new AllowBreaksAttribute(true);
var_dump($allowBreaks);
print_r($allowBreaks);
?>
--EXPECTF--
object(Pango\Attribute\AllowBreaksAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  bool(true)
}
Pango\Attribute\AllowBreaksAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 1
)