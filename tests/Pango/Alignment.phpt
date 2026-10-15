--TEST--
Pango\Alignment enum
--EXTENSIONS--
pango
--FILE--
<?php
var_dump(Pango\Alignment::cases());
?>
--EXPECTF--
array(3) {
  [0]=>
  enum(Pango\Alignment::Left)
  [1]=>
  enum(Pango\Alignment::Center)
  [2]=>
  enum(Pango\Alignment::Right)
}
