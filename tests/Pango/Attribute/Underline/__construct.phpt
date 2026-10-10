--TEST--
Pango\Attribute\Underline::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Underline;

$underline = new Underline(Pango\Underline::Double);
var_dump($underline);

try {
    new Underline();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Underline(Pango\Underline::Double, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Underline(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\Underline)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Underline::Double)
}
Pango\Attribute\Underline::__construct() expects at least 1 argument, 0 given
Pango\Attribute\Underline::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\Underline::__construct(): Argument #1 ($value) must be of type Pango\Underline, array given
