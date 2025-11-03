--TEST--
Pango\Layout::getContext()
--EXTENSIONS--
pango
cairo
--FILE--
<?php
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);

$pangoContext = new Pango\Context($fontMap);
var_dump($pangoContext);

$layout = new Pango\Layout($pangoContext);
var_dump($layout);

var_dump($layout->getContext());
var_dump($layout->getContext());

try {
    $layout->getContext(array());
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
Pango\Layout::getContext() expects exactly 0 arguments, 1 given
