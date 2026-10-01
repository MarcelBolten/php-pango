--TEST--
Pango\Attribute\ForegroundAlpha get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\ForegroundAlpha;

$foregroundAlpha = new ForegroundAlpha(5);
var_dump($foregroundAlpha);
print_r($foregroundAlpha);
?>
--EXPECTF--
object(Pango\Attribute\ForegroundAlpha)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(5)
}
Pango\Attribute\ForegroundAlpha Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 5
)