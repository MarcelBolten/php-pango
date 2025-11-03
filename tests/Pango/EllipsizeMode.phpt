--TEST--
Pango\EllipsizeMode enum
--EXTENSIONS--
pango
--FILE--
<?php
var_dump(Pango\EllipsizeMode::cases());
?>
--EXPECTF--
array(4) {
  [0]=>
  enum(Pango\EllipsizeMode::None)
  [1]=>
  enum(Pango\EllipsizeMode::Start)
  [2]=>
  enum(Pango\EllipsizeMode::Middle)
  [3]=>
  enum(Pango\EllipsizeMode::End)
}
