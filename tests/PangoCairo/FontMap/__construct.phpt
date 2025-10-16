--TEST--
PangoCairo\FontMap::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use PangoCairo\FontMap;

var_dump(new FontMap());

try {
    new FontMap(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
PangoCairo\FontMap::__construct() expects exactly 0 arguments, 1 given
