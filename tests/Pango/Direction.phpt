--TEST--
Pango\Direction enum
--EXTENSIONS--
pango
--FILE--
<?php
var_dump(Pango\Direction::cases());
?>
--EXPECTF--
array(5) {
  [0]=>
  enum(Pango\Direction::LTR)
  [1]=>
  enum(Pango\Direction::RTL)
  [2]=>
  enum(Pango\Direction::WeakLTR)
  [3]=>
  enum(Pango\Direction::WeakRTL)
  [4]=>
  enum(Pango\Direction::Neutral)
}
