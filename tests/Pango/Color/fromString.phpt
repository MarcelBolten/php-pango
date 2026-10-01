--TEST--
Pango\Color::fromString
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Color;

$color = Color::fromString("#FFF888111");
var_dump($color);

Color::fromString("firebrick");

try {
    var_dump(Color::fromString("#FFF\0888111"));
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    var_dump(Color::fromString("not a valid color name"));
} catch (Pango\Exception $e) {
    echo $e->getMessage(), "\n";
}

try {
    Color::fromString();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    Color::fromString("#FFF888111", "extra_argument");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    Color::fromString(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Color)#1 (3) {
  ["red"]=>
  int(65535)
  ["green"]=>
  int(34952)
  ["blue"]=>
  int(4369)
}
Pango\Color::fromString(): Argument #1 ($string) must not contain NUL bytes
Failed to parse color from string
Pango\Color::fromString() expects exactly 1 argument, 0 given
Pango\Color::fromString() expects exactly 1 argument, 2 given
Pango\Color::fromString(): Argument #1 ($string) must be of type string, array given
