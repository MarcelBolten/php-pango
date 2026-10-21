--TEST--
Pango\Attribute\WeightAttribute::__construct()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\WeightAttribute;

$weightCase = Pango\Weight::Bold;
$weight = new WeightAttribute($weightCase);
var_dump($weight);

try {
    new WeightAttribute($weightCase, -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new WeightAttribute($weightCase, PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new WeightAttribute($weightCase, endIndex: -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new WeightAttribute($weightCase, endIndex: PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new WeightAttribute($weightCase, 30, 20);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new WeightAttribute();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new WeightAttribute($weightCase, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new WeightAttribute(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\WeightAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Weight::Bold)
}
Pango\Attribute\WeightAttribute::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but -1 given
Pango\Attribute\WeightAttribute::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but 9223372036854775807 given
Pango\Attribute\WeightAttribute::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but -1 given
Pango\Attribute\WeightAttribute::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but 9223372036854775807 given
Pango\Attribute\WeightAttribute::__construct(): Argument #3 ($endIndex) must be greater than 30 and at most 4294967295, but 20 given
Pango\Attribute\WeightAttribute::__construct() expects at least 1 argument, 0 given
Pango\Attribute\WeightAttribute::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\WeightAttribute::__construct(): Argument #1 ($value) must be of type Pango\Weight, array given
