--TEST--
PangoCairo\FontMap::__construct()
--EXTENSIONS--
pango
--FILE--
<?php
use PangoCairo\FontMap;

var_dump(new FontMap());

try {
    new FontMap(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
PangoCairo\FontMap::__construct() expects exactly 0 arguments, 1 given
