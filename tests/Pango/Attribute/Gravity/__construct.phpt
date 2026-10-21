--TEST--
Pango\Attribute\GravityAttribute::__construct()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\GravityAttribute;

$gravityCase = Pango\Gravity::East;
$gravity = new GravityAttribute($gravityCase);
var_dump($gravity);

try {
    new GravityAttribute($gravityCase, -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new GravityAttribute($gravityCase, PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new GravityAttribute($gravityCase, endIndex: -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new GravityAttribute($gravityCase, endIndex: PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new GravityAttribute($gravityCase, 30, 20);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new GravityAttribute();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new GravityAttribute(Pango\Gravity::North, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new GravityAttribute(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\GravityAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Gravity::East)
}
Pango\Attribute\GravityAttribute::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but -1 given
Pango\Attribute\GravityAttribute::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but 9223372036854775807 given
Pango\Attribute\GravityAttribute::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but -1 given
Pango\Attribute\GravityAttribute::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but 9223372036854775807 given
Pango\Attribute\GravityAttribute::__construct(): Argument #3 ($endIndex) must be greater than 30 and at most 4294967295, but 20 given
Pango\Attribute\GravityAttribute::__construct() expects at least 1 argument, 0 given
Pango\Attribute\GravityAttribute::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\GravityAttribute::__construct(): Argument #1 ($value) must be of type Pango\Gravity, array given
