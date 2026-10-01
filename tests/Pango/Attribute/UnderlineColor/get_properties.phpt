--TEST--
Pango\Attribute\UnderlineColor get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\UnderlineColor;

$underlineColor = new UnderlineColor(new Pango\Color(1024, 2048, 4096));
var_dump($underlineColor);
print_r($underlineColor);
?>
--EXPECTF--
object(Pango\Attribute\UnderlineColor)#%d (3) {
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
Pango\Attribute\UnderlineColor Object
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
