--TEST--
Pango\Layout::getHeight()
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
var_dump($layout->getHeight());

// Set in terms of lines (2 lines)
$layout->setHeight(-2);
var_dump($layout->getHeight());

// Set in terms of Pango units (10 * Pango::SCALE)
$layout->setHeight(10 * Pango\Pango::SCALE);
var_dump($layout->getHeight());

try {
    $layout->getHeight('wrong');
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
int(-1)
int(-2)
int(10240)
Pango\Layout::getHeight() expects exactly 0 arguments, 1 given
