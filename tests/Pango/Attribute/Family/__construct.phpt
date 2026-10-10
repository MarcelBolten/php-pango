--TEST--
Pango\Attribute\Family::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Family;

$family = new Family("Arial");
var_dump($family);

$family = new Family("Arial, Times New Roman, sans-serif");
assert(gettype($family) === 'object');

try {
    new Family("Arial,\0Times New Roman");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Family("Arial", -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Family("Arial", PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Family("Arial", endIndex: -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Family("Arial", endIndex: PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Family("Arial", 30, 20);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Family();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Family("Arial", 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Family(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\Family)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  string(5) "Arial"
}
Pango\Attribute\Family::__construct(): Argument #1 ($value) must not contain NUL bytes
Pango\Attribute\Family::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but -1 given
Pango\Attribute\Family::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but 9223372036854775807 given
Pango\Attribute\Family::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but -1 given
Pango\Attribute\Family::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but 9223372036854775807 given
Pango\Attribute\Family::__construct(): Argument #3 ($endIndex) must be greater than 30 and at most 4294967295, but 20 given
Pango\Attribute\Family::__construct() expects at least 1 argument, 0 given
Pango\Attribute\Family::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\Family::__construct(): Argument #1 ($value) must be of type string, array given
