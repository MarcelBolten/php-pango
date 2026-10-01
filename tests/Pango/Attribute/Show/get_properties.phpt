--TEST--
Pango\Attribute\Show get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Show;

$show = new Show(Show::NONE);
var_dump($show);
print_r($show);
?>
--EXPECTF--
object(Pango\Attribute\Show)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(0)
}
Pango\Attribute\Show Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 0
)