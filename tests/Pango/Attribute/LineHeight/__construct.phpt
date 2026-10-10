--TEST--
Pango\Attribute\LineHeight::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\LineHeight;

$LineHeight = new LineHeight(42.5);
var_dump($LineHeight);

try {
    new LineHeight();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new LineHeight(42.5, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new LineHeight(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\LineHeight)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  float(42.5)
}
Pango\Attribute\LineHeight::__construct() expects at least 1 argument, 0 given
Pango\Attribute\LineHeight::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\LineHeight::__construct(): Argument #1 ($value) must be of type float, array given
