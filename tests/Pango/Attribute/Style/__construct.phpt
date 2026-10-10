--TEST--
Pango\Attribute\Style::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Style;

$styleCase = Pango\Style::Italic;
$style = new Style($styleCase);
var_dump($style);

try {
    new Style($styleCase, -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Style($styleCase, PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Style($styleCase, endIndex: -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Style($styleCase, endIndex: PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Style($styleCase, 30, 20);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Style();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Style(Pango\Style::Italic, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Style(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\Style)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Style::Italic)
}
Pango\Attribute\Style::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but -1 given
Pango\Attribute\Style::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but 9223372036854775807 given
Pango\Attribute\Style::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but -1 given
Pango\Attribute\Style::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but 9223372036854775807 given
Pango\Attribute\Style::__construct(): Argument #3 ($endIndex) must be greater than 30 and at most 4294967295, but 20 given
Pango\Attribute\Style::__construct() expects at least 1 argument, 0 given
Pango\Attribute\Style::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\Style::__construct(): Argument #1 ($value) must be of type Pango\Style, array given
