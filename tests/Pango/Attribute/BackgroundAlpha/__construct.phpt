--TEST--
Pango\Attribute\BackgroundAlpha::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\BackgroundAlpha;

$backgroundAlpha = new BackgroundAlpha(42);
var_dump($backgroundAlpha);

try {
    new BackgroundAlpha();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new BackgroundAlpha(42, 123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new BackgroundAlpha(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\BackgroundAlpha)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(42)
}
Pango\Attribute\BackgroundAlpha::__construct() expects exactly 1 argument, 0 given
Pango\Attribute\BackgroundAlpha::__construct() expects exactly 1 argument, 2 given
Pango\Attribute\BackgroundAlpha::__construct(): Argument #1 ($value) must be of type int, array given
