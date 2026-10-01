--TEST--
Pango\Layout::setText()
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

$layout->setText("Hello, Παν語!");
var_dump($layout->getText());

$layout->setText("");
var_dump($layout->getText());

// with NUL byte
try {
    $layout->setText("Hello,\0 Παν語!");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setText();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setText("Hello", "Παν語!");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setText(array());
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
string(17) "Hello, Παν語!"
string(0) ""
Pango\Layout::setText(): Argument #1 ($text) must not contain NUL bytes
Pango\Layout::setText() expects exactly 1 argument, 0 given
Pango\Layout::setText() expects exactly 1 argument, 2 given
Pango\Layout::setText(): Argument #1 ($text) must be of type string, array given
