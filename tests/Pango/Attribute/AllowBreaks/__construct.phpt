--TEST--
Pango\Attribute\AllowBreaks::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AllowBreaks;

$allowBreaks = new AllowBreaks(true);
var_dump($allowBreaks);

try {
    new AllowBreaks();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new AllowBreaks(true, 123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new AllowBreaks(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\AllowBreaks)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  bool(true)
}
Pango\Attribute\AllowBreaks::__construct() expects exactly 1 argument, 0 given
Pango\Attribute\AllowBreaks::__construct() expects exactly 1 argument, 2 given
Pango\Attribute\AllowBreaks::__construct(): Argument #1 ($value) must be of type bool, array given
