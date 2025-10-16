--TEST--
PangoCairo\FontMap::getDefault()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use PangoCairo\FontMap;

var_dump(FontMap::getDefault());

try {
    FontMap::getDefault(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
PangoCairo\FontMap::getDefault() expects exactly 0 arguments, 1 given
