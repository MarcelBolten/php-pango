--TEST--
Pango\Attribute\Variant::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Variant;

$variant = new Variant(Pango\Variant::SmallCaps);
var_dump($variant);

try {
    new Variant();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Variant(Pango\Variant::SmallCaps, 123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Variant(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\Variant)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Variant::SmallCaps)
}
Pango\Attribute\Variant::__construct() expects exactly 1 argument, 0 given
Pango\Attribute\Variant::__construct() expects exactly 1 argument, 2 given
Pango\Attribute\Variant::__construct(): Argument #1 ($value) must be of type Pango\Variant, array given
