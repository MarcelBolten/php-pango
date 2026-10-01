--TEST--
Pango\Attribute\Family clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Family;

$family = new Family("Arial");
var_dump($family);

$copy = clone $family;
var_dump($copy);
?>
--EXPECT--
object(Pango\Attribute\Family)#1 (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  string(5) "Arial"
}
object(Pango\Attribute\Family)#2 (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  string(5) "Arial"
}