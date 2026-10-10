--TEST--
Pango\Attribute\Stretch::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Stretch;

$stretchCase = Pango\Stretch::Expanded;
$stretch = new Stretch($stretchCase);
var_dump($stretch);

try {
    new Stretch($stretchCase, -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Stretch($stretchCase, PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Stretch($stretchCase, endIndex: -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Stretch($stretchCase, endIndex: PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Stretch($stretchCase, 30, 20);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Stretch();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Stretch(Pango\Stretch::Expanded, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Stretch(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\Stretch)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Stretch::Expanded)
}
Pango\Attribute\Stretch::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but -1 given
Pango\Attribute\Stretch::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but 9223372036854775807 given
Pango\Attribute\Stretch::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but -1 given
Pango\Attribute\Stretch::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but 9223372036854775807 given
Pango\Attribute\Stretch::__construct(): Argument #3 ($endIndex) must be greater than 30 and at most 4294967295, but 20 given
Pango\Attribute\Stretch::__construct() expects at least 1 argument, 0 given
Pango\Attribute\Stretch::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\Stretch::__construct(): Argument #1 ($value) must be of type Pango\Stretch, array given
