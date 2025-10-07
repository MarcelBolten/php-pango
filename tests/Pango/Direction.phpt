--TEST--
Pango\Direction enum
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
?>
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
  enum(Pango\Direction::Weak_LTR)
  [3]=>
  enum(Pango\Direction::Weak_RTL)
  [4]=>
  enum(Pango\Direction::Neutral)
}
