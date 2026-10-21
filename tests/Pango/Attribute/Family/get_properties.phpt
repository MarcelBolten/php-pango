--TEST--
Pango\Attribute\FamilyAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\FamilyAttribute;

$family = new FamilyAttribute("Noto Sans");
var_dump($family);
print_r($family);
?>
--EXPECTF--
object(Pango\Attribute\FamilyAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  string(%d) "%s"
}
Pango\Attribute\FamilyAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Noto Sans
)