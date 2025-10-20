--TEST--
Pango\Layout::getLine()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
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

$line = $layout->getLine(0);
var_dump($line);

try {
    $layout->getLine();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->getLine(1, 2);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->getLine(array());
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
Pango\Layout::getLine() expects exactly 1 argument, 0 given
Pango\Layout::getLine() expects exactly 1 argument, 2 given
Pango\Layout::getLine(): Argument #1 ($lineIndex) must be of type int, array given
