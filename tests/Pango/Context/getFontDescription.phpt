--TEST--
Pango\Context::getFontDescription()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$context = new Pango\Context();
var_dump($context);
var_dump($context->getFontDescription());

try {
    $context->getFontDescription(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Context)#%d (0) {
}
NULL
Pango\Context::getFontDescription() expects exactly 0 arguments, 1 given
