--TEST--
Pango\Attribute\Gravity::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Gravity;

$gravity = new Gravity(Pango\Gravity::East);
var_dump($gravity);

try {
    new Gravity();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Gravity(Pango\Gravity::North, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Gravity(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\Gravity)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Gravity::East)
}
Pango\Attribute\Gravity::__construct() expects at least 1 argument, 0 given
Pango\Attribute\Gravity::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\Gravity::__construct(): Argument #1 ($value) must be of type Pango\Gravity, array given
