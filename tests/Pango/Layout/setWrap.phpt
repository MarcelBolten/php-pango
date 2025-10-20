--TEST--
Pango\Layout::setWrap()
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

var_dump($layout->getWrap());

$layout->setWrap(Pango\WrapMode::Char);
var_dump($layout->getWrap());

try {
    $layout->setWrap();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setWrap(Pango\WrapMode::Word, 'wrong');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setWrap('left');
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
enum(Pango\WrapMode::Word)
enum(Pango\WrapMode::Char)
Pango\Layout::setWrap() expects exactly 1 argument, 0 given
Pango\Layout::setWrap() expects exactly 1 argument, 2 given
Pango\Layout::setWrap(): Argument #1 ($wrap) must be of type Pango\WrapMode, string given
