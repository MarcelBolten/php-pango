--TEST--
Pango\GravityHint enum
--EXTENSIONS--
pango
--FILE--
<?php
var_dump(Pango\GravityHint::cases());
?>
--EXPECTF--
array(3) {
  [0]=>
  enum(Pango\GravityHint::Natural)
  [1]=>
  enum(Pango\GravityHint::Strong)
  [2]=>
  enum(Pango\GravityHint::Line)
}
