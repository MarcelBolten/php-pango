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
    new BaselineShift(1024, -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new BaselineShift(1024, PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new BaselineShift(1024, endIndex: -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new BaselineShift(1024, endIndex: PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new BaselineShift(1024, 30, 20);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new BaselineShift();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new BaselineShift(Pango\BaselineShift::Subscript, 1, 2, 3);
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
Pango\Attribute\BaselineShift::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but -1 given
Pango\Attribute\BaselineShift::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but 9223372036854775807 given
Pango\Attribute\BaselineShift::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but -1 given
Pango\Attribute\BaselineShift::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but 9223372036854775807 given
Pango\Attribute\BaselineShift::__construct(): Argument #3 ($endIndex) must be greater than 30 and at most 4294967295, but 20 given
Pango\Attribute\BaselineShift::__construct() expects at least 1 argument, 0 given
Pango\Attribute\BaselineShift::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\BaselineShift::__construct(): Argument #1 ($value) must be of type Pango\BaselineShift|int, array given
