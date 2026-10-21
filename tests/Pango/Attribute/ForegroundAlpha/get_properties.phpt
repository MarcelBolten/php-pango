--TEST--
Pango\Attribute\ForegroundAlphaAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\ForegroundAlphaAttribute;

$foregroundAlpha = new ForegroundAlphaAttribute(5);
var_dump($foregroundAlpha);
print_r($foregroundAlpha);
?>
--EXPECTF--
object(Pango\Attribute\ForegroundAlphaAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(5)
}
Pango\Attribute\ForegroundAlphaAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 5
)