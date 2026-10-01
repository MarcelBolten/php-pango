--TEST--
Pango\Attribute\Width::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Width;

$width = new Width(1024 * 10);
var_dump($width);

try {
    new Width();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Width(42, 123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Width(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\Width)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(10240)
}
Pango\Attribute\Width::__construct() expects exactly 1 argument, 0 given
Pango\Attribute\Width::__construct() expects exactly 1 argument, 2 given
Pango\Attribute\Width::__construct(): Argument #1 ($value) must be of type int, array given
