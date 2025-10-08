--TEST--
Pango\RoundingMode enum
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
?>
--FILE--
<?php
var_dump(Pango\RoundingMode::cases());
?>
--EXPECTF--
array(2) {
  [0]=>
  enum(Pango\RoundingMode::Inclusive)
  [1]=>
  enum(Pango\RoundingMode::Nearest)
}
