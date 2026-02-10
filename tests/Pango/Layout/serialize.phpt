--TEST--
Pango\Layout::serialize()
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

$layout->setText('Hello, Παν語!');
var_dump($layout->serialize());

var_dump(str_replace(array("\r", "\n"), '', $layout->serialize(
    Pango\Layout::SERIALIZE_CONTEXT
    | Pango\Layout::SERIALIZE_OUTPUT
)));

try {
    $layout->serialize(1, 2);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->serialize(array());
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
string(35) "{
  "text" : "Hello, Παν語!"
}
"
string(%d) %s
Pango\Layout::serialize() expects at most 1 argument, 2 given
Pango\Layout::serialize(): Argument #1 ($flags) must be of type int, array given
