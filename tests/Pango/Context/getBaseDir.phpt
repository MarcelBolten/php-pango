--TEST--
Pango\Context::getBaseDir()
--EXTENSIONS--
pango
--FILE--
<?php
$context = new Pango\Context();
var_dump($context);
var_dump($context->getBaseDir());

try {
    $context->getBaseDir(array());
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Context)#%d (0) {
}
enum(Pango\Direction::WeakLTR)
Pango\Context::getBaseDir() expects exactly 0 arguments, 1 given
