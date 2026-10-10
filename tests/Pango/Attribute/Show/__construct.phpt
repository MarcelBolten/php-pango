--TEST--
Pango\Attribute\Show::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Show;

$show = new Show(Show::NONE);
var_dump($show);

try {
    new Show(-1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Show(8);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Show(Show::NONE, -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Show(Show::NONE, PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Show(Show::NONE, endIndex: -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Show(Show::NONE, endIndex: PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Show(Show::NONE, 30, 20);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Show();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Show(Show::NONE, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Show(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\Show)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(0)
}
Pango\Attribute\Show::__construct(): Argument #1 ($value) must be a class constant of Pango\Attribute\Show or a combination of them
Pango\Attribute\Show::__construct(): Argument #1 ($value) must be a class constant of Pango\Attribute\Show or a combination of them
Pango\Attribute\Show::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but -1 given
Pango\Attribute\Show::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but 9223372036854775807 given
Pango\Attribute\Show::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but -1 given
Pango\Attribute\Show::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but 9223372036854775807 given
Pango\Attribute\Show::__construct(): Argument #3 ($endIndex) must be greater than 30 and at most 4294967295, but 20 given
Pango\Attribute\Show::__construct() expects at least 1 argument, 0 given
Pango\Attribute\Show::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\Show::__construct(): Argument #1 ($value) must be of type int, array given
