--TEST--
Pango\Gravity enum
--EXTENSIONS--
pango
--FILE--
<?php
var_dump(Pango\Gravity::cases());
?>
--EXPECTF--
array(5) {
  [0]=>
  enum(Pango\Gravity::South)
  [1]=>
  enum(Pango\Gravity::East)
  [2]=>
  enum(Pango\Gravity::North)
  [3]=>
  enum(Pango\Gravity::West)
  [4]=>
  enum(Pango\Gravity::Auto)
}
