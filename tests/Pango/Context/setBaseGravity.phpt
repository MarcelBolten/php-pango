--TEST--
Pango\Context::setBaseGravity()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$context = new Pango\Context();
var_dump($context);
var_dump($context->getBaseGravity());

$context->setBaseGravity(Pango\Gravity::North);
var_dump($context->getBaseGravity());

try {
    $context->setBaseGravity();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->setBaseGravity(Pango\Gravity::North, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->setBaseGravity(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Context)#%d (0) {
}
enum(Pango\Gravity::South)
enum(Pango\Gravity::North)
Pango\Context::setBaseGravity() expects exactly 1 argument, 0 given
Pango\Context::setBaseGravity() expects exactly 1 argument, 2 given
Pango\Context::setBaseGravity(): Argument #1 ($gravity) must be of type Pango\Gravity, array given
