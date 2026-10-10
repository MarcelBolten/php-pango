--TEST--
Pango\Attribute\FontFeatures::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\FontFeatures;

$fontFeatures = new FontFeatures("kern=0, liga=0");
var_dump($fontFeatures);

try {
    new FontFeatures("kern=0,\0liga=0");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new FontFeatures("kern=0, liga=0", -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new FontFeatures("kern=0, liga=0", PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new FontFeatures("kern=0, liga=0", endIndex: -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new FontFeatures("kern=0, liga=0", endIndex: PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new FontFeatures("kern=0, liga=0", 30, 20);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new FontFeatures();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new FontFeatures("Arial", 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new FontFeatures(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\FontFeatures)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  string(14) "kern=0, liga=0"
}
Pango\Attribute\FontFeatures::__construct(): Argument #1 ($value) must not contain NUL bytes
Pango\Attribute\FontFeatures::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but -1 given
Pango\Attribute\FontFeatures::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but 9223372036854775807 given
Pango\Attribute\FontFeatures::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but -1 given
Pango\Attribute\FontFeatures::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but 9223372036854775807 given
Pango\Attribute\FontFeatures::__construct(): Argument #3 ($endIndex) must be greater than 30 and at most 4294967295, but 20 given
Pango\Attribute\FontFeatures::__construct() expects at least 1 argument, 0 given
Pango\Attribute\FontFeatures::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\FontFeatures::__construct(): Argument #1 ($value) must be of type string, array given
