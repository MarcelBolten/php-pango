--TEST--
Pango\Context::getLanguage()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$context = new Pango\Context();
var_dump($context);
var_dump($context->getLanguage());

try {
    $context->getLanguage(array());
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Context)#%d (0) {
}
NULL
Pango\Context::getLanguage() expects exactly 0 arguments, 1 given
