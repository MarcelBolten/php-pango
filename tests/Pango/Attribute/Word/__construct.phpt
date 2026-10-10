--TEST--
Pango\Attribute\Word::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Word;

$word = new Word();
var_dump($word);

try {
    new Word(-1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Word(PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Word(endIndex: -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Word(endIndex: PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Word(30, 20);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Word(1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\Word)#%d (2) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
}
Pango\Attribute\Word::__construct(): Argument #1 ($startIndex) must be between 0 and 4294967295 but -1 given
Pango\Attribute\Word::__construct(): Argument #1 ($startIndex) must be between 0 and 4294967295 but 9223372036854775807 given
Pango\Attribute\Word::__construct(): Argument #2 ($endIndex) must be greater than 0 and at most 4294967295, but -1 given
Pango\Attribute\Word::__construct(): Argument #2 ($endIndex) must be greater than 0 and at most 4294967295, but 9223372036854775807 given
Pango\Attribute\Word::__construct(): Argument #2 ($endIndex) must be greater than 30 and at most 4294967295, but 20 given
Pango\Attribute\Word::__construct() expects at most 2 arguments, 3 given
