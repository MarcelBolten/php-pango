--TEST--
Pango\Attribute\FallbackAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\FallbackAttribute;

$fallback = new FallbackAttribute(true);
var_dump($fallback);
print_r($fallback);
?>
--EXPECTF--
object(Pango\Attribute\FallbackAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  bool(true)
}
Pango\Attribute\FallbackAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 1
)