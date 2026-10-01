--TEST--
Pango\Color get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$color = new Pango\Color(1024, 2048, 4096);
var_dump($color);
print_r($color);
?>
--EXPECTF--
object(Pango\Color)#1 (3) {
  ["red"]=>
  int(1024)
  ["green"]=>
  int(2048)
  ["blue"]=>
  int(4096)
}
Pango\Color Object
(
    [red] => 1024
    [green] => 2048
    [blue] => 4096
)
