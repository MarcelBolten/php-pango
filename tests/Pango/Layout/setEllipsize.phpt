--TEST--
Pango\Layout::setEllipsize()
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

var_dump($layout->getEllipsize());

$layout->setEllipsize(Pango\EllipsizeMode::Middle);
var_dump($layout->getEllipsize());

try {
    $layout->setEllipsize();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setEllipsize(Pango\EllipsizeMode::End, 'wrong');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setEllipsize('middle');
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
enum(Pango\EllipsizeMode::None)
enum(Pango\EllipsizeMode::Middle)
Pango\Layout::setEllipsize() expects exactly 1 argument, 0 given
Pango\Layout::setEllipsize() expects exactly 1 argument, 2 given
Pango\Layout::setEllipsize(): Argument #1 ($mode) must be of type Pango\EllipsizeMode, string given
