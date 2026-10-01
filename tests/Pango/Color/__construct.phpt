--TEST--
Pango\Color::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Color;

$color = new Color(1024, 2048, 4096);
var_dump($color);

try {
    new Color(0x10000, 0, 0);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Color(0, 0x10000, 0);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Color(0, 0, 0x10000);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Color();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Color(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Color(1, 2);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Color(1, 2, 3, 4);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Color(array(), 1, 1);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Color(1, array(), 1);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Color(1, 1, array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
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
Pango\Color::__construct(): Argument #1 ($red) must be equal or greater than 0 and smaller or equal than 65536
Pango\Color::__construct(): Argument #2 ($green) must be equal or greater than 0 and smaller or equal than 65536
Pango\Color::__construct(): Argument #3 ($blue) must be equal or greater than 0 and smaller or equal than 65536
Pango\Color::__construct() expects exactly 3 arguments, 0 given
Pango\Color::__construct() expects exactly 3 arguments, 1 given
Pango\Color::__construct() expects exactly 3 arguments, 2 given
Pango\Color::__construct() expects exactly 3 arguments, 4 given
Pango\Color::__construct(): Argument #1 ($red) must be of type int, array given
Pango\Color::__construct(): Argument #2 ($green) must be of type int, array given
Pango\Color::__construct(): Argument #3 ($blue) must be of type int, array given
