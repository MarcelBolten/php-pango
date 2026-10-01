--TEST--
Pango\Attribute\BackgroundAlpha get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\BackgroundAlpha;

$backgroundAlpha = new BackgroundAlpha(5);
var_dump($backgroundAlpha);
print_r($backgroundAlpha);
?>
--EXPECTF--
object(Pango\Attribute\BackgroundAlpha)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(5)
}
Pango\Attribute\BackgroundAlpha Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 5
)