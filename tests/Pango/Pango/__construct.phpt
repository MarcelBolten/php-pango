--TEST--
Pango\Pango new object
--EXTENSIONS--
pango
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
