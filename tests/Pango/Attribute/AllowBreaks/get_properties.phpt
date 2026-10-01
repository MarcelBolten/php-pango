--TEST--
Pango\Attribute\AllowBreaks get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AllowBreaks;

$allowBreaks = new AllowBreaks(true);
var_dump($allowBreaks);
print_r($allowBreaks);
?>
--EXPECTF--
object(Pango\Attribute\AllowBreaks)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  bool(true)
}
Pango\Attribute\AllowBreaks Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 1
)