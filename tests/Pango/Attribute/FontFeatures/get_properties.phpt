--TEST--
Pango\Attribute\FontFeaturesAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\FontFeaturesAttribute;

$fontFeatures = new FontFeatures("kern=0");
var_dump($fontFeatures);
print_r($fontFeatures);
?>
--EXPECTF--
object(Pango\Attribute\FontFeaturesAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  string(6) "kern=0"
}
Pango\Attribute\FontFeaturesAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => kern=0
)