--TEST--
Pango\Layout::getLineReadonly()
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

$layout->setText("100");

$line = $layout->getLineReadonly(0);
var_dump($line);

try {
    $layout->getLineReadonly();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->getLineReadonly(1, 2);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->getLineReadonly(array());
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
object(Pango\LayoutLine)#%d (0) {
}
Pango\Layout::getLineReadonly() expects exactly 1 argument, 0 given
Pango\Layout::getLineReadonly() expects exactly 1 argument, 2 given
Pango\Layout::getLineReadonly(): Argument #1 ($lineIndex) must be of type int, array given
