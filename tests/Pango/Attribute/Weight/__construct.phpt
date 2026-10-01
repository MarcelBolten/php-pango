--TEST--
Pango\Attribute\Weight::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Weight;

$weight = new Weight(Pango\Weight::Bold);
var_dump($weight);

try {
    new Weight();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Weight(Pango\Weight::Bold, 123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Weight(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\Weight)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Weight::Bold)
}
Pango\Attribute\Weight::__construct() expects exactly 1 argument, 0 given
Pango\Attribute\Weight::__construct() expects exactly 1 argument, 2 given
Pango\Attribute\Weight::__construct(): Argument #1 ($value) must be of type Pango\Weight, array given
