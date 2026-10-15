--TEST--
PangoCairo\Context::setResolution()
--EXTENSIONS--
pango
cairo
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$pangoContext = new PangoCairo\Context($cairoContext);
var_dump($pangoContext);
$pangoContext->setResolution(300);

try {
    $pangoContext->setResolution();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $pangoContext->setResolution(1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $pangoContext->setResolution(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Context)#%d (0) {
}
PangoCairo\Context::setResolution() expects exactly 1 argument, 0 given
PangoCairo\Context::setResolution() expects exactly 1 argument, 2 given
PangoCairo\Context::setResolution(): Argument #1 ($dpi) must be of type float, array given
