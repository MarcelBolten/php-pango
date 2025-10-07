--TEST--
Pango\Exception new object
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
try {
    throw new Pango\Exception("test exception");
} catch (Pango\Exception $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
test exception
