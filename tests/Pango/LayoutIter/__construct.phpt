--TEST--
Pango\LayoutIter::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
try {
    var_dump(new Pango\LayoutIter());
} catch (Error $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
Call to private Pango\LayoutIter::__construct() from global scope
