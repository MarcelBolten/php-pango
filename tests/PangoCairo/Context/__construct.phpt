--TEST--
PangoCairo\Context::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
use PangoCairo\Context;

$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

var_dump(new Context($cairoContext));

try {
    new Context();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Context($cairoContext, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Context(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Context)#%d (0) {
}
PangoCairo\Context::__construct() expects exactly 1 argument, 0 given
PangoCairo\Context::__construct() expects exactly 1 argument, 2 given
PangoCairo\Context::__construct(): Argument #1 ($context) must be of type Cairo\Context, array given
