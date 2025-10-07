--TEST--
Pango\WrapMode enum
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
?>
--FILE--
<?php
var_dump(Pango\WrapMode::cases());
?>
--EXPECTF--
array(4) {
  [0]=>
  enum(Pango\WrapMode::Word)
  [1]=>
  enum(Pango\WrapMode::Char)
  [2]=>
  enum(Pango\WrapMode::WordChar)
  [3]=>
  enum(Pango\WrapMode::None)
}
