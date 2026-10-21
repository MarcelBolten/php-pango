--TEST--
Pango\Attribute\WordAttribute::__construct()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\WordAttribute;

$word = new WordAttribute();
var_dump($word);

try {
    new WordAttribute(-1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new WordAttribute(PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new WordAttribute(endIndex: -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new WordAttribute(endIndex: PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new WordAttribute(30, 20);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new WordAttribute(1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\WordAttribute)#%d (2) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
}
Pango\Attribute\WordAttribute::__construct(): Argument #1 ($startIndex) must be between 0 and 4294967295 but -1 given
Pango\Attribute\WordAttribute::__construct(): Argument #1 ($startIndex) must be between 0 and 4294967295 but 9223372036854775807 given
Pango\Attribute\WordAttribute::__construct(): Argument #2 ($endIndex) must be greater than 0 and at most 4294967295, but -1 given
Pango\Attribute\WordAttribute::__construct(): Argument #2 ($endIndex) must be greater than 0 and at most 4294967295, but 9223372036854775807 given
Pango\Attribute\WordAttribute::__construct(): Argument #2 ($endIndex) must be greater than 30 and at most 4294967295, but 20 given
Pango\Attribute\WordAttribute::__construct() expects at most 2 arguments, 3 given
