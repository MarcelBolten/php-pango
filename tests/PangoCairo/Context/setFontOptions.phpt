--TEST--
PangoCairo\Context::setFontOptions()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$pangoContext = new PangoCairo\Context($cairoContext);
var_dump($pangoContext);

$pangoContext->setFontOptions(null);
var_dump($pangoContext->getFontOptions());

$newFontOptions = new Cairo\FontOptions();
var_dump($newFontOptions);

$pangoContext->setFontOptions($newFontOptions);
$fontOptionsRetrieved = $pangoContext->getFontOptions();
var_dump($fontOptionsRetrieved);
var_dump($fontOptionsRetrieved === $newFontOptions);

try {
    $pangoContext->setFontOptions();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $pangoContext->setFontOptions(1, 2);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $pangoContext->setFontOptions(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Context)#%d (0) {
}
NULL
object(Cairo\FontOptions)#%d (0) {
}
object(Cairo\FontOptions)#%d (0) {
}
bool(true)
PangoCairo\Context::setFontOptions() expects exactly 1 argument, 0 given
PangoCairo\Context::setFontOptions() expects exactly 1 argument, 2 given
PangoCairo\Context::setFontOptions(): Argument #1 ($options) must be of type ?Cairo\FontOptions, array given
