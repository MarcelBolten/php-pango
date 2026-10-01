--TEST--
Pango\Attribute\GravityHint::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\GravityHint;

$gravityHint = new GravityHint(Pango\GravityHint::Strong);
var_dump($gravityHint);

try {
    new GravityHint();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new GravityHint(Pango\GravityHint::Strong, 123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new GravityHint(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\GravityHint)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\GravityHint::Strong)
}
Pango\Attribute\GravityHint::__construct() expects exactly 1 argument, 0 given
Pango\Attribute\GravityHint::__construct() expects exactly 1 argument, 2 given
Pango\Attribute\GravityHint::__construct(): Argument #1 ($value) must be of type Pango\GravityHint, array given
