--TEST--
Pango\Context::getBaseGravity()
--EXTENSIONS--
pango
cairo
--FILE--
<?php
$context = new Pango\Context();
var_dump($context);
var_dump($context->getBaseGravity());

try {
    $context->getBaseGravity(array());
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Context)#%d (0) {
}
enum(Pango\Gravity::South)
Pango\Context::getBaseGravity() expects exactly 0 arguments, 1 given
