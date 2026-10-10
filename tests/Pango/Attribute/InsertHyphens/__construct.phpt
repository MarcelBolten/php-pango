--TEST--
Pango\Attribute\InsertHyphens::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\InsertHyphens;

$insertHyphens = new InsertHyphens(true);
var_dump($insertHyphens);

try {
    new InsertHyphens();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new InsertHyphens(true, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new InsertHyphens(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\InsertHyphens)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  bool(true)
}
Pango\Attribute\InsertHyphens::__construct() expects at least 1 argument, 0 given
Pango\Attribute\InsertHyphens::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\InsertHyphens::__construct(): Argument #1 ($value) must be of type bool, array given
