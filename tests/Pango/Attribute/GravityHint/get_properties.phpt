--TEST--
Pango\Attribute\GravityHintAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\GravityHintAttribute;

$gravityHint = new GravityHint(Pango\GravityHint::Strong);
var_dump($gravityHint);
print_r($gravityHint);
?>
--EXPECTF--
object(Pango\Attribute\GravityHintAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\GravityHint::Strong)
}
Pango\Attribute\GravityHintAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\GravityHint Enum:int
        (
            [name] => Strong
            [value] => 1
        )

)
