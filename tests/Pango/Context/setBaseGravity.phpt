--TEST--
Pango\Context::setBaseGravity()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$layout = new Pango\Layout($cairoContext);
var_dump($layout);

$context = $layout->getContext();
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
object(Cairo\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
enum(Pango\Gravity::South)
enum(Pango\Gravity::North)
Pango\Context::setBaseGravity() expects exactly 1 argument, 0 given
Pango\Context::setBaseGravity() expects exactly 1 argument, 2 given
Pango\Context::setBaseGravity(): Argument #1 ($gravity) must be of type Pango\Gravity, array given
