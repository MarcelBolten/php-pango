--TEST--
Pango\Attribute\Overline::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Overline;

$overline = new Overline(Pango\Overline::Single);
var_dump($overline);

try {
    new Overline();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Overline(Pango\Overline::Single, 123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Overline(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\Overline)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Overline::Single)
}
Pango\Attribute\Overline::__construct() expects exactly 1 argument, 0 given
Pango\Attribute\Overline::__construct() expects exactly 1 argument, 2 given
Pango\Attribute\Overline::__construct(): Argument #1 ($value) must be of type Pango\Overline, array given
