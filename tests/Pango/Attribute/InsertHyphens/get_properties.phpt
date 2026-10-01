--TEST--
Pango\Attribute\InsertHyphens get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\InsertHyphens;

$insertHyphens = new InsertHyphens(true);
var_dump($insertHyphens);
print_r($insertHyphens);
?>
--EXPECTF--
object(Pango\Attribute\InsertHyphens)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  bool(true)
}
Pango\Attribute\InsertHyphens Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 1
)