--TEST--
Pango\Attribute\GravityHint get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\GravityHint;

$gravityHint = new GravityHint(Pango\GravityHint::Strong);
var_dump($gravityHint);
print_r($gravityHint);
?>
--EXPECTF--
object(Pango\Attribute\GravityHint)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\GravityHint::Strong)
}
Pango\Attribute\GravityHint Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\GravityHint Enum:int
        (
            [name] => Strong
            [value] => 1
        )

)
