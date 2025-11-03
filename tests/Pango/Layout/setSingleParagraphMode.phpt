--TEST--
Pango\Layout::setSingleParagraphMode()
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

$layout->setSingleParagraphMode(true);
var_dump($layout->getSingleParagraphMode());

$layout->setSingleParagraphMode(false);
var_dump($layout->getSingleParagraphMode());

try {
    $layout->setSingleParagraphMode();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setSingleParagraphMode(true, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setSingleParagraphMode(array());
} catch (TypeError $e) {
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
bool(true)
bool(false)
Pango\Layout::setSingleParagraphMode() expects exactly 1 argument, 0 given
Pango\Layout::setSingleParagraphMode() expects exactly 1 argument, 2 given
Pango\Layout::setSingleParagraphMode(): Argument #1 ($setting) must be of type bool, array given
