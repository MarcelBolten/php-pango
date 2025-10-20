--TEST--
Pango\Context::getGravity()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$context = new Pango\Context();
var_dump($context);
var_dump($context->getGravity());

try {
    $context->getGravity(array());
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Context)#%d (0) {
}
enum(Pango\Gravity::South)
Pango\Context::getGravity() expects exactly 0 arguments, 1 given
