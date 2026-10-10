--TEST--
Pango\Attribute\Sentence::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Sentence;

$sentence = new Sentence();
var_dump($sentence);

try {
    new Sentence(-1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Sentence(PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Sentence(endIndex: -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Sentence(endIndex: PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Sentence(30, 20);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Sentence(1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\Sentence)#%d (2) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
}
Pango\Attribute\Sentence::__construct(): Argument #1 ($startIndex) must be between 0 and 4294967295 but -1 given
Pango\Attribute\Sentence::__construct(): Argument #1 ($startIndex) must be between 0 and 4294967295 but 9223372036854775807 given
Pango\Attribute\Sentence::__construct(): Argument #2 ($endIndex) must be greater than 0 and at most 4294967295, but -1 given
Pango\Attribute\Sentence::__construct(): Argument #2 ($endIndex) must be greater than 0 and at most 4294967295, but 9223372036854775807 given
Pango\Attribute\Sentence::__construct(): Argument #2 ($endIndex) must be greater than 30 and at most 4294967295, but 20 given
Pango\Attribute\Sentence::__construct() expects at most 2 arguments, 3 given
