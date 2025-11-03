--TEST--
PangoCairo\Context::getFontMap()
--EXTENSIONS--
pango
cairo
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$pangoContext = new PangoCairo\Context($cairoContext);
var_dump($pangoContext);
var_dump($pangoContext->getFontMap());

try {
    $pangoContext->getFontMap(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Context)#%d (0) {
}
object(PangoCairo\FontMap)#%d (0) {
}
Pango\Context::getFontMap() expects exactly 0 arguments, 1 given
