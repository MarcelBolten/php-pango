--TEST--
Pango\Context::getFontMap()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$context = new Pango\Context();
var_dump($context);
var_dump($context->getFontMap());

try {
    $context->getFontMap(array());
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Context)#%d (0) {
}
NULL
Pango\Context::getFontMap() expects exactly 0 arguments, 1 given
