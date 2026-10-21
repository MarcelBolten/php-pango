--TEST--
Pango\Attribute\FontFeaturesAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\FontFeaturesAttribute;

$fontFeatures = new FontFeatures("kern=0");
var_dump($fontFeatures);

$copy = clone $fontFeatures;
var_dump($copy);
?>
--EXPECT--
object(Pango\Attribute\FontFeaturesAttribute)#1 (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  string(6) "kern=0"
}
object(Pango\Attribute\FontFeaturesAttribute)#2 (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  string(6) "kern=0"
}