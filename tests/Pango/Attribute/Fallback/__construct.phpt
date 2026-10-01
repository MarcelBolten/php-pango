--TEST--
Pango\Attribute\Fallback::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Fallback;

$fallback = new Fallback(true);
var_dump($fallback);

try {
    new Fallback();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Fallback(true, 123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Fallback(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\Fallback)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  bool(true)
}
Pango\Attribute\Fallback::__construct() expects exactly 1 argument, 0 given
Pango\Attribute\Fallback::__construct() expects exactly 1 argument, 2 given
Pango\Attribute\Fallback::__construct(): Argument #1 ($value) must be of type bool, array given
