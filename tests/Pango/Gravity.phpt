--TEST--
Pango\Gravity enum
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
?>
--FILE--
<?php
var_dump(Pango\Gravity::cases());

var_dump(Pango\Gravity::South->toRotation());
var_dump(Pango\Gravity::East->toRotation());
var_dump(Pango\Gravity::North->toRotation());
var_dump(Pango\Gravity::West->toRotation());
try {
  var_dump(Pango\Gravity::Auto->toRotation());
} catch (ValueError $e) {
  echo $e->getMessage(), "\n";
}
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
float(0)
float(-1.5707963267948966)
float(3.141592653589793)
float(1.5707963267948966)
Pango\Gravity::Auto cannot be converted to a rotation
