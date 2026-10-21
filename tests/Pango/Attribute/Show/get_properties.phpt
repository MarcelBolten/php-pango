--TEST--
Pango\Attribute\ShowAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\ShowAttribute;

$show = new Show(Show::NONE);
var_dump($show);
print_r($show);
?>
--EXPECTF--
object(Pango\Attribute\ShowAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(0)
}
Pango\Attribute\ShowAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 0
)