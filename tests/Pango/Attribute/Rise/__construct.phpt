--TEST--
Pango\Attribute\Rise::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Rise;

$rise = new Rise(42);
var_dump($rise);

try {
    new Rise();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Rise(42, 123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Rise(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\Rise)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(42)
}
Pango\Attribute\Rise::__construct() expects exactly 1 argument, 0 given
Pango\Attribute\Rise::__construct() expects exactly 1 argument, 2 given
Pango\Attribute\Rise::__construct(): Argument #1 ($value) must be of type int, array given
