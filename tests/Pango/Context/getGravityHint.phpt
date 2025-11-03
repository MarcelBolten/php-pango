--TEST--
Pango\Context::getGravityHint()
--EXTENSIONS--
pango
--FILE--
<?php
$context = new Pango\Context();
var_dump($context);
var_dump($context->getGravityHint());

try {
    $context->getGravityHint(array());
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Context)#%d (0) {
}
enum(Pango\GravityHint::Natural)
Pango\Context::getGravityHint() expects exactly 0 arguments, 1 given
