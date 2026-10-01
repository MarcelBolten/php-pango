--TEST--
Pango\Attribute\StrikethroughColor::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\StrikethroughColor;

$color = new Pango\Color(1024, 2048, 4096);
$strikethroughColor = new StrikethroughColor($color);
var_dump($strikethroughColor);

try {
    new StrikethroughColor();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new StrikethroughColor($color, 123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new StrikethroughColor(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
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
Pango\Attribute\StrikethroughColor::__construct() expects exactly 1 argument, 0 given
Pango\Attribute\StrikethroughColor::__construct() expects exactly 1 argument, 2 given
Pango\Attribute\StrikethroughColor::__construct(): Argument #1 ($color) must be of type Pango\Color, array given
