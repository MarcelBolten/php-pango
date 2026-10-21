--TEST--
Pango\Attribute\InsertHyphensAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\InsertHyphensAttribute;

$insertHyphens = new InsertHyphensAttribute(true);
var_dump($insertHyphens);
print_r($insertHyphens);
?>
--EXPECTF--
object(Pango\Attribute\InsertHyphensAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  bool(true)
}
Pango\Attribute\InsertHyphensAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 1
)