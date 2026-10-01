--TEST--
Pango\Attribute\Weight get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Weight;

$weight = new Weight(Pango\Weight::Bold);
var_dump($weight);
print_r($weight);
?>
--EXPECTF--
object(Pango\Attribute\Weight)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Weight::Bold)
}
Pango\Attribute\Weight Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\Weight Enum:int
        (
            [name] => Bold
            [value] => 700
        )

)
