--TEST--
Pango\Attribute\AbsoluteSize::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AbsoluteSize;

$pangoSize = new AbsoluteSize(42);
var_dump($pangoSize);

try {
    new AbsoluteSize();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new AbsoluteSize(42, 123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new AbsoluteSize(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\AbsoluteSize)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(42)
}
Pango\Attribute\AbsoluteSize::__construct() expects exactly 1 argument, 0 given
Pango\Attribute\AbsoluteSize::__construct() expects exactly 1 argument, 2 given
Pango\Attribute\AbsoluteSize::__construct(): Argument #1 ($value) must be of type int, array given
