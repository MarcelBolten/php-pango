--TEST--
Pango\Attribute\ShapeAttribute::__construct()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\ShapeAttribute;
use Pango\Rectangle;

$rect = new Rectangle(0, 10, 100, 200);
$shape = new ShapeAttribute($rect, $rect);
var_dump($shape);

try {
    new ShapeAttribute($rect, $rect, -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ShapeAttribute($rect, $rect, PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ShapeAttribute($rect, $rect, endIndex: -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ShapeAttribute($rect, $rect, endIndex: PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ShapeAttribute($rect, $rect, 30, 20);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ShapeAttribute();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ShapeAttribute($rect);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ShapeAttribute($rect, $rect, 0, 1, 2);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ShapeAttribute(array(), $rect);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ShapeAttribute($rect, array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\ShapeAttribute)#%d (4) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["inkRect"]=>
  object(Pango\Rectangle)#%d (8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(10)
    ["width"]=>
    int(100)
    ["height"]=>
    int(200)
    ["ascent"]=>
    int(-10)
    ["descent"]=>
    int(210)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(100)
  }
  ["logicalRect"]=>
  object(Pango\Rectangle)#%d (8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(10)
    ["width"]=>
    int(100)
    ["height"]=>
    int(200)
    ["ascent"]=>
    int(-10)
    ["descent"]=>
    int(210)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(100)
  }
}
Pango\Attribute\ShapeAttribute::__construct(): Argument #3 ($startIndex) must be between 0 and 4294967295 but -1 given
Pango\Attribute\ShapeAttribute::__construct(): Argument #3 ($startIndex) must be between 0 and 4294967295 but 9223372036854775807 given
Pango\Attribute\ShapeAttribute::__construct(): Argument #4 ($endIndex) must be greater than 0 and at most 4294967295, but -1 given
Pango\Attribute\ShapeAttribute::__construct(): Argument #4 ($endIndex) must be greater than 0 and at most 4294967295, but 9223372036854775807 given
Pango\Attribute\ShapeAttribute::__construct(): Argument #4 ($endIndex) must be greater than 30 and at most 4294967295, but 20 given
Pango\Attribute\ShapeAttribute::__construct() expects at least 2 arguments, 0 given
Pango\Attribute\ShapeAttribute::__construct() expects at least 2 arguments, 1 given
Pango\Attribute\ShapeAttribute::__construct() expects at most 4 arguments, 5 given
Pango\Attribute\ShapeAttribute::__construct(): Argument #1 ($inkRect) must be of type Pango\Rectangle, array given
Pango\Attribute\ShapeAttribute::__construct(): Argument #2 ($logicalRect) must be of type Pango\Rectangle, array given
