--TEST--
Pango\Attribute\StrikethroughColor get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\StrikethroughColor;

$strikethroughColor = new StrikethroughColor(new Pango\Color(1024, 2048, 4096));
var_dump($strikethroughColor);
print_r($strikethroughColor);
?>
--EXPECTF--
object(Pango\Attribute\StrikethroughColor)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["color"]=>
  object(Pango\Color)#%d (3) {
    ["red"]=>
    int(1024)
    ["green"]=>
    int(2048)
    ["blue"]=>
    int(4096)
  }
}
Pango\Attribute\StrikethroughColor Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [color] => Pango\Color Object
        (
            [red] => 1024
            [green] => 2048
            [blue] => 4096
        )

)
