--TEST--
Pango\Attribute\BackgroundAlphaAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\BackgroundAlphaAttribute;

$backgroundAlpha = new BackgroundAlpha(5);
var_dump($backgroundAlpha);
print_r($backgroundAlpha);
?>
--EXPECTF--
object(Pango\Attribute\BackgroundAlphaAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(5)
}
Pango\Attribute\BackgroundAlphaAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 5
)