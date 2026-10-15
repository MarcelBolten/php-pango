--TEST--
PangoCairo\Context::getFontOptions()
--EXTENSIONS--
pango
cairo
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$pangoContext = new PangoCairo\Context($cairoContext);
var_dump($pangoContext);

$fontOptions = $pangoContext->getFontOptions();
var_dump($fontOptions);

try {
    $pangoContext->getFontOptions(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Context)#%d (0) {
}
object(Cairo\FontOptions)#%d (0) {
}
PangoCairo\Context::getFontOptions() expects exactly 0 arguments, 1 given
