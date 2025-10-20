--TEST--
Pango\Layout::__construct()
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

try {
    new Pango\Layout();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Pango\Layout(1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Pango\Layout(array());
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
Pango\Layout::__construct() expects exactly 1 argument, 0 given
Pango\Layout::__construct() expects exactly 1 argument, 2 given
Pango\Layout::__construct(): Argument #1 ($context) must be of type Pango\Context, array given
