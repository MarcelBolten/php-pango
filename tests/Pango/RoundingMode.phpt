--TEST--
Pango\RoundingMode enum
--EXTENSIONS--
pango
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
