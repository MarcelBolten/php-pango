--TEST--
Pango\Attribute\Strikethrough::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Strikethrough;

$strikethrough = new Strikethrough(true);
var_dump($strikethrough);

try {
    new Strikethrough();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Strikethrough(true, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Strikethrough(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\Strikethrough)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  bool(true)
}
Pango\Attribute\Strikethrough::__construct() expects at least 1 argument, 0 given
Pango\Attribute\Strikethrough::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\Strikethrough::__construct(): Argument #1 ($value) must be of type bool, array given
