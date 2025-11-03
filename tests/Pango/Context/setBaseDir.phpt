--TEST--
Pango\Context::setBaseDir()
--EXTENSIONS--
pango
--FILE--
<?php
$context = new Pango\Context();
var_dump($context);
var_dump($context->getBaseDir());

$context->setBaseDir(Pango\Direction::RTL);
var_dump($context->getBaseDir());

try {
    $context->setBaseDir();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->setBaseDir(Pango\Direction::LTR, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->setBaseDir(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Context)#%d (0) {
}
enum(Pango\Direction::WeakLTR)
enum(Pango\Direction::RTL)
Pango\Context::setBaseDir() expects exactly 1 argument, 0 given
Pango\Context::setBaseDir() expects exactly 1 argument, 2 given
Pango\Context::setBaseDir(): Argument #1 ($direction) must be of type Pango\Direction, array given
