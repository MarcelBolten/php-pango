--TEST--
Pango\Attribute\Fallback get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Fallback;

$fallback = new Fallback(true);
var_dump($fallback);
print_r($fallback);
?>
--EXPECTF--
object(Pango\Attribute\Fallback)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  bool(true)
}
Pango\Attribute\Fallback Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 1
)