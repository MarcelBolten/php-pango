--TEST--
Pango\Attribute\FamilyAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\FamilyAttribute;

$family = new FamilyAttribute("Arial");
var_dump($family);

$copy = clone $family;
var_dump($copy);
?>
--EXPECT--
object(Pango\Attribute\FamilyAttribute)#1 (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  string(5) "Arial"
}
object(Pango\Attribute\FamilyAttribute)#2 (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  string(5) "Arial"
}