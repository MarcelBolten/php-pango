--TEST--
Pango\Attribute\OverlineColor::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\OverlineColor;

$color = new Pango\Color(1024, 2048, 4096);
$overlineColor = new OverlineColor($color);
var_dump($overlineColor);

try {
    new OverlineColor($color, -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new OverlineColor($color, PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new OverlineColor($color, endIndex: -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new OverlineColor($color, endIndex: PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new OverlineColor($color, 30, 20);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new OverlineColor();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new OverlineColor($color, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new OverlineColor(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\OverlineColor)#%d (3) {
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
Pango\Attribute\OverlineColor::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but -1 given
Pango\Attribute\OverlineColor::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but 9223372036854775807 given
Pango\Attribute\OverlineColor::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but -1 given
Pango\Attribute\OverlineColor::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but 9223372036854775807 given
Pango\Attribute\OverlineColor::__construct(): Argument #3 ($endIndex) must be greater than 30 and at most 4294967295, but 20 given
Pango\Attribute\OverlineColor::__construct() expects at least 1 argument, 0 given
Pango\Attribute\OverlineColor::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\OverlineColor::__construct(): Argument #1 ($color) must be of type Pango\Color, array given
