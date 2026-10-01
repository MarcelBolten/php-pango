--TEST--
Pango\Attribute\FontFeatures get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\FontFeatures;

$fontFeatures = new FontFeatures("kern=0");
var_dump($fontFeatures);
print_r($fontFeatures);
?>
--EXPECTF--
object(Pango\Attribute\FontFeatures)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  string(6) "kern=0"
}
Pango\Attribute\FontFeatures Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => kern=0
)