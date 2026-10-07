--TEST--
Pango\Color::fromStringWithAlpha
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Color;

// with alpha
$color = Color::fromStringWithAlpha("#ff881180");
var_dump($color);

// without alpha
$color = Color::fromStringWithAlpha("#ff8811");
var_dump($color);

var_dump(Color::fromStringWithAlpha("firebrick"));

try {
    var_dump(Color::fromStringWithAlpha("#FFF\0888111"));
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    var_dump(Color::fromStringWithAlpha("not a valid color name"));
} catch (Pango\Exception $e) {
    echo $e->getMessage(), "\n";
}

try {
    Color::fromStringWithAlpha();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    Color::fromStringWithAlpha("#FFF888111", "extra_argument");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    Color::fromStringWithAlpha(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
array(2) {
  ["color"]=>
  object(Pango\Color)#%d (3) {
    ["red"]=>
    int(65535)
    ["green"]=>
    int(34952)
    ["blue"]=>
    int(4369)
  }
  ["alpha"]=>
  int(32896)
}
array(2) {
  ["color"]=>
  object(Pango\Color)#%d (3) {
    ["red"]=>
    int(65535)
    ["green"]=>
    int(34952)
    ["blue"]=>
    int(4369)
  }
  ["alpha"]=>
  int(65535)
}
array(2) {
  ["color"]=>
  object(Pango\Color)#%d (3) {
    ["red"]=>
    int(45746)
    ["green"]=>
    int(8738)
    ["blue"]=>
    int(8738)
  }
  ["alpha"]=>
  int(65535)
}
Pango\Color::fromStringWithAlpha(): Argument #1 ($string) must not contain NUL bytes
Failed to parse color with alpha from string
Pango\Color::fromStringWithAlpha() expects exactly 1 argument, 0 given
Pango\Color::fromStringWithAlpha() expects exactly 1 argument, 2 given
Pango\Color::fromStringWithAlpha(): Argument #1 ($string) must be of type string, array given
