--TEST--
Pango\Attribute\Attribute new object
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
try {
    $attribute = new Pango\Attribute\Attribute();
    var_dump($attribute);
} catch (Error $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
Cannot instantiate abstract class Pango\Attribute\Attribute
