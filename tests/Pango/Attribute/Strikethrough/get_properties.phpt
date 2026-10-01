--TEST--
Pango\Attribute\Strikethrough get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Strikethrough;

$strikethrough = new Strikethrough(true);
var_dump($strikethrough);
print_r($strikethrough);
?>
--EXPECTF--
object(Pango\Attribute\Strikethrough)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  bool(true)
}
Pango\Attribute\Strikethrough Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 1
)