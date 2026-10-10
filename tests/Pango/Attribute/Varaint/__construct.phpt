--TEST--
Pango\Attribute\Variant::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Variant;

$variantCase = Pango\Variant::SmallCaps;
$variant = new Variant($variantCase);
var_dump($variant);

try {
    new Variant($variantCase, -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Variant($variantCase, PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Variant($variantCase, endIndex: -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Variant($variantCase, endIndex: PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Variant($variantCase, 30, 20);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Variant();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Variant(Pango\Variant::SmallCaps, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Variant(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\Variant)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Variant::SmallCaps)
}
Pango\Attribute\Variant::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but -1 given
Pango\Attribute\Variant::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but 9223372036854775807 given
Pango\Attribute\Variant::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but -1 given
Pango\Attribute\Variant::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but 9223372036854775807 given
Pango\Attribute\Variant::__construct(): Argument #3 ($endIndex) must be greater than 30 and at most 4294967295, but 20 given
Pango\Attribute\Variant::__construct() expects at least 1 argument, 0 given
Pango\Attribute\Variant::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\Variant::__construct(): Argument #1 ($value) must be of type Pango\Variant, array given
