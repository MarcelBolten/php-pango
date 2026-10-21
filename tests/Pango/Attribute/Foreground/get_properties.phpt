--TEST--
Pango\Attribute\ForegroundAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\ForegroundAttribute;

$foreground = new ForegroundAttribute(new Pango\Color(1024, 2048, 4096));
var_dump($foreground);
print_r($foreground);
?>
--EXPECTF--
object(Pango\Attribute\ForegroundAttribute)#%d (3) {
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
Pango\Attribute\ForegroundAttribute Object
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
