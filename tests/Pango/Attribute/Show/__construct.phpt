--TEST--
Pango\Attribute\ShowAttribute::__construct()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\ShowAttribute;

$show = new ShowAttribute(ShowAttribute::NONE);
var_dump($show);

try {
    new ShowAttribute(-1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ShowAttribute(8);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ShowAttribute(ShowAttribute::NONE, -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ShowAttribute(ShowAttribute::NONE, PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ShowAttribute(ShowAttribute::NONE, endIndex: -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ShowAttribute(ShowAttribute::NONE, endIndex: PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ShowAttribute(ShowAttribute::NONE, 30, 20);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ShowAttribute();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ShowAttribute(ShowAttribute::NONE, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ShowAttribute(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\ShowAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(0)
}
Pango\Attribute\ShowAttribute::__construct(): Argument #1 ($value) must be a class constant of Pango\Attribute\ShowAttribute or a combination of them
Pango\Attribute\ShowAttribute::__construct(): Argument #1 ($value) must be a class constant of Pango\Attribute\ShowAttribute or a combination of them
Pango\Attribute\ShowAttribute::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but -1 given
Pango\Attribute\ShowAttribute::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but 9223372036854775807 given
Pango\Attribute\ShowAttribute::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but -1 given
Pango\Attribute\ShowAttribute::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but 9223372036854775807 given
Pango\Attribute\ShowAttribute::__construct(): Argument #3 ($endIndex) must be greater than 30 and at most 4294967295, but 20 given
Pango\Attribute\ShowAttribute::__construct() expects at least 1 argument, 0 given
Pango\Attribute\ShowAttribute::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\ShowAttribute::__construct(): Argument #1 ($value) must be of type int, array given
