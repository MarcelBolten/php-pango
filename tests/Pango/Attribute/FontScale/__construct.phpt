--TEST--
Pango\Attribute\FontScale::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\FontScale;

$fontScale = new FontScale(Pango\FontScale::SmallCaps);
var_dump($fontScale);

try {
    new FontScale();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new FontScale(Pango\FontScale::SmallCaps, 123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new FontScale(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\FontScale)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\FontScale::SmallCaps)
}
Pango\Attribute\FontScale::__construct() expects exactly 1 argument, 0 given
Pango\Attribute\FontScale::__construct() expects exactly 1 argument, 2 given
Pango\Attribute\FontScale::__construct(): Argument #1 ($value) must be of type Pango\FontScale, array given
