--TEST--
Pango\Context::getBaseGravity()
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

try {
    $context->getBaseGravity(array());
} catch (ArgumentCountError $e) {
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
Pango\Context::getBaseGravity() expects exactly 0 arguments, 1 given
