--TEST--
Pango\Attribute\BaselineShift::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\BaselineShift;

$baselineShift = new BaselineShift(Pango\BaselineShift::Subscript);
var_dump($baselineShift);

$baselineShift = new BaselineShift(1024 * 10);
var_dump($baselineShift);

try {
    new BaselineShift();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new BaselineShift(Pango\BaselineShift::Subscript, 123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new BaselineShift(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\BaselineShift)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\BaselineShift::Subscript)
}
object(Pango\Attribute\BaselineShift)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(10240)
}
Pango\Attribute\BaselineShift::__construct() expects exactly 1 argument, 0 given
Pango\Attribute\BaselineShift::__construct() expects exactly 1 argument, 2 given
Pango\Attribute\BaselineShift::__construct(): Argument #1 ($value) must be of type Pango\BaselineShift|int, array given
