--TEST--
Pango\Layout::setAutoDir()
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

$layout->setAutoDir(true);
var_dump($layout->getAutoDir());
$layout->setAutoDir(false);
var_dump($layout->getAutoDir());

try {
    $layout->setAutoDir();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setAutoDir(true, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setAutoDir(array());
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
Pango\Layout::setAutoDir() expects exactly 1 argument, 0 given
Pango\Layout::setAutoDir() expects exactly 1 argument, 2 given
Pango\Layout::setAutoDir(): Argument #1 ($autoDir) must be of type bool, array given
