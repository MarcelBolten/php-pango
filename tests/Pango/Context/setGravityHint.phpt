--TEST--
Pango\Context::setGravityHint()
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
var_dump($context->getGravityHint());

$context->setGravityHint(Pango\GravityHint::Strong);
var_dump($context->getGravityHint());

try {
    $context->setGravityHint();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->setGravityHint(Pango\GravityHint::Natural, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->setGravityHint(array());
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
enum(Pango\GravityHint::Natural)
enum(Pango\GravityHint::Strong)
Pango\Context::setGravityHint() expects exactly 1 argument, 0 given
Pango\Context::setGravityHint() expects exactly 1 argument, 2 given
Pango\Context::setGravityHint(): Argument #1 ($hint) must be of type Pango\GravityHint, array given
