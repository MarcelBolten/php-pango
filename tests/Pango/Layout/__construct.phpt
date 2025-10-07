--TEST--
Pango\Layout::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$layout = new Pango\Layout($cairoContext);
var_dump($layout);

try {
    new Pango\Layout($cairoContext, $cairoContext);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
// TODO: investigate memory leak if unset is removed
unset($layout);
// only calling the code below without previous call to Pango\Layout::__construct() works fine
try {
    new Pango\Layout(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
Pango\Layout::__construct() expects exactly 1 argument, 2 given
Pango\Layout::__construct(): Argument #1 ($context) must be of type Cairo\Context, array given
