--TEST--
Pango\Context::getSerial()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$context = new Pango\Context();
var_dump($context);
var_dump($context->getSerial());

try {
    $context->getSerial(array());
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Context)#%d (0) {
}
int(%d)
Pango\Context::getSerial() expects exactly 0 arguments, 1 given
