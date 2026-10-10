--TEST--
Pango\Attribute\BackgroundAlpha::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\BackgroundAlpha;

$backgroundAlpha = new BackgroundAlpha(42);
var_dump($backgroundAlpha);

try {
    new BackgroundAlpha(-1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new BackgroundAlpha(PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new BackgroundAlpha(42, -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new BackgroundAlpha(42, PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new BackgroundAlpha(42, endIndex: -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new BackgroundAlpha(42, endIndex: PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new BackgroundAlpha(42, 30, 20);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new BackgroundAlpha();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new BackgroundAlpha(42, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new BackgroundAlpha(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\BackgroundAlpha)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(42)
}
Pango\Attribute\BackgroundAlpha::__construct(): Argument #1 ($value) must be between 0 and 65535 but -1 given
Pango\Attribute\BackgroundAlpha::__construct(): Argument #1 ($value) must be between 0 and 65535 but 9223372036854775807 given
Pango\Attribute\BackgroundAlpha::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but -1 given
Pango\Attribute\BackgroundAlpha::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but 9223372036854775807 given
Pango\Attribute\BackgroundAlpha::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but -1 given
Pango\Attribute\BackgroundAlpha::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but 9223372036854775807 given
Pango\Attribute\BackgroundAlpha::__construct(): Argument #3 ($endIndex) must be greater than 30 and at most 4294967295, but 20 given
Pango\Attribute\BackgroundAlpha::__construct() expects at least 1 argument, 0 given
Pango\Attribute\BackgroundAlpha::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\BackgroundAlpha::__construct(): Argument #1 ($value) must be of type int, array given
