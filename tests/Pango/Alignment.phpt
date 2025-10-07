--TEST--
Pango\Alignment enum
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
?>
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
