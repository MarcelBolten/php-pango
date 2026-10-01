--TEST--
Pango\Ft2\FontMap::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Ft2\FontMap;

var_dump(new FontMap());

try {
    new FontMap(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Ft2\FontMap)#%d (0) {
}
Pango\Ft2\FontMap::__construct() expects exactly 0 arguments, 1 given
