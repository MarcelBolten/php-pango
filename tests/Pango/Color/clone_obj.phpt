--TEST--
Pango\Color clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$color = new Pango\Color(1024, 2048, 4096);
var_dump($color);
var_dump(clone $color);
?>
--EXPECT--
object(Pango\Color)#1 (3) {
  ["red"]=>
  int(1024)
  ["green"]=>
  int(2048)
  ["blue"]=>
  int(4096)
}
object(Pango\Color)#2 (3) {
  ["red"]=>
  int(1024)
  ["green"]=>
  int(2048)
  ["blue"]=>
  int(4096)
}
