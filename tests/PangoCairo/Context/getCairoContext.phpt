--TEST--
PangoCairo\Context::getCairoContext()
--EXTENSIONS--
pango
cairo
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$pangoContext = new PangoCairo\Context($cairoContext);
var_dump($pangoContext);

$cairoContextRetrieved = $pangoContext->getCairoContext();
var_dump($cairoContextRetrieved);
var_dump($cairoContext === $cairoContextRetrieved);

try {
    $pangoContext->getCairoContext(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Context)#%d (0) {
}
object(Cairo\Context)#%d (0) {
}
bool(true)
PangoCairo\Context::getCairoContext() expects exactly 0 arguments, 1 given
