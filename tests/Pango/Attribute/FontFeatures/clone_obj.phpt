--TEST--
Pango\Attribute\FontFeatures clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\FontFeatures;

$fontFeatures = new FontFeatures("kern=0");
var_dump($fontFeatures);

$copy = clone $fontFeatures;
var_dump($copy);
?>
--EXPECT--
object(Pango\Attribute\FontFeatures)#1 (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  string(6) "kern=0"
}
object(Pango\Attribute\FontFeatures)#2 (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  string(6) "kern=0"
}