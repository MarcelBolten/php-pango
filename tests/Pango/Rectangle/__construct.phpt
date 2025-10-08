--TEST--
Pango\Rectangle::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Rectangle;

$params = [1, 2, 100, 20];
array_walk($params, fn (&$v) => $v = $v * Pango\Pango::SCALE);

$rectangle = new Rectangle(...$params);
var_dump($rectangle);

try {
    new Rectangle();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    new Rectangle(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    new Rectangle(1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    new Rectangle(1, 1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    new Rectangle(1, 1, 1, 1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    new Rectangle(array(), 1, 1, 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    new Rectangle(1, array(), 1, 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    new Rectangle(1, 1, array(), 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    new Rectangle(1, 1, 1, array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
?>
--EXPECTF--
object(Pango\Rectangle)#1 (8) {
  ["x"]=>
  int(1024)
  ["y"]=>
  int(2048)
  ["width"]=>
  int(102400)
  ["height"]=>
  int(20480)
  ["ascent"]=>
  int(-2048)
  ["descent"]=>
  int(22528)
  ["leftBearing"]=>
  int(1024)
  ["rightBearing"]=>
  int(103424)
}
Pango\Rectangle::__construct() expects exactly 4 arguments, 0 given
Pango\Rectangle::__construct() expects exactly 4 arguments, 1 given
Pango\Rectangle::__construct() expects exactly 4 arguments, 2 given
Pango\Rectangle::__construct() expects exactly 4 arguments, 3 given
Pango\Rectangle::__construct() expects exactly 4 arguments, 5 given
Pango\Rectangle::__construct(): Argument #1 ($x) must be of type int, array given
Pango\Rectangle::__construct(): Argument #2 ($y) must be of type int, array given
Pango\Rectangle::__construct(): Argument #3 ($width) must be of type int, array given
Pango\Rectangle::__construct(): Argument #4 ($height) must be of type int, array given
