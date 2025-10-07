--TEST--
Pango\Pango new object
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
try {
    $pango = new Pango\Pango();
    var_dump($pango);
} catch (Error $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
Cannot instantiate abstract class Pango\Pango
