--TEST--
Pango\Attribute\AbsoluteSizeAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\AbsoluteSizeAttribute;

$absoluteSize = new AbsoluteSizeAttribute(5);
var_dump($absoluteSize);
print_r($absoluteSize);
?>
--EXPECTF--
object(Pango\Attribute\AbsoluteSizeAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(5)
}
Pango\Attribute\AbsoluteSizeAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 5
)