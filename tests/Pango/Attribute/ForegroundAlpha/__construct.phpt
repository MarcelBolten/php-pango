--TEST--
Pango\Attribute\ForegroundAlpha::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\ForegroundAlpha;

$foregroundAlpha = new ForegroundAlpha(42);
var_dump($foregroundAlpha);

try {
    new ForegroundAlpha();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ForegroundAlpha(42, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ForegroundAlpha(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\ForegroundAlpha)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(42)
}
Pango\Attribute\ForegroundAlpha::__construct() expects at least 1 argument, 0 given
Pango\Attribute\ForegroundAlpha::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\ForegroundAlpha::__construct(): Argument #1 ($value) must be of type int, array given
