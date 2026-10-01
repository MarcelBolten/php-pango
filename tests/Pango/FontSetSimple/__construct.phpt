--TEST--
Pango\FontSetSimple::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\FontSetSimple;
use Pango\Language;

$fss = new FontSetSimple(new Language("en"));
var_dump($fss);

try {
    new FontSetSimple();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new FontSetSimple(new Language("en"), 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new FontSetSimple(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontSetSimple)#%d (1) {
  ["size"]=>
  int(0)
}
Pango\FontSetSimple::__construct() expects exactly 1 argument, 0 given
Pango\FontSetSimple::__construct() expects exactly 1 argument, 2 given
Pango\FontSetSimple::__construct(): Argument #1 ($language) must be of type Pango\Language, array given
