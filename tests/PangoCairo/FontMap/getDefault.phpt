--TEST--
PangoCairo\FontMap::getDefault()
--EXTENSIONS--
pango
--FILE--
<?php
use PangoCairo\FontMap;

var_dump(FontMap::getDefault());

try {
    FontMap::getDefault(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
PangoCairo\FontMap::getDefault() expects exactly 0 arguments, 1 given
