--TEST--
Pango\Attribute\StyleAttribute::__construct()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\StyleAttribute;

$styleCase = Pango\Style::Italic;
$style = new StyleAttribute($styleCase);
var_dump($style);

try {
    new StyleAttribute($styleCase, -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new StyleAttribute($styleCase, PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new StyleAttribute($styleCase, endIndex: -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new StyleAttribute($styleCase, endIndex: PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new StyleAttribute($styleCase, 30, 20);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new StyleAttribute();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new StyleAttribute(Pango\Style::Italic, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new StyleAttribute(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\StyleAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Style::Italic)
}
Pango\Attribute\StyleAttribute::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but -1 given
Pango\Attribute\StyleAttribute::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but 9223372036854775807 given
Pango\Attribute\StyleAttribute::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but -1 given
Pango\Attribute\StyleAttribute::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but 9223372036854775807 given
Pango\Attribute\StyleAttribute::__construct(): Argument #3 ($endIndex) must be greater than 30 and at most 4294967295, but 20 given
Pango\Attribute\StyleAttribute::__construct() expects at least 1 argument, 0 given
Pango\Attribute\StyleAttribute::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\StyleAttribute::__construct(): Argument #1 ($value) must be of type Pango\Style, array given
