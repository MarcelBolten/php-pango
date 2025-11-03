--TEST--
PangoCairo\Layout::__construct()
--EXTENSIONS--
pango
cairo
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$layout = new PangoCairo\Layout($cairoContext);
var_dump($layout);

try {
    new PangoCairo\Layout();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new PangoCairo\Layout($cairoContext, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
// TODO: investigate memory leak if unset is removed
unset($layout);
// only calling the code below without previous call to PangoCairo\Layout::__construct() works fine
try {
    new PangoCairo\Layout(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
PangoCairo\Layout::__construct() expects exactly 1 argument, 0 given
PangoCairo\Layout::__construct() expects exactly 1 argument, 2 given
PangoCairo\Layout::__construct(): Argument #1 ($context) must be of type Cairo\Context, array given
