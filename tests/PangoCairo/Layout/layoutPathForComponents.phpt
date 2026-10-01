--TEST--
PangoCairo\Layout::layoutPathForComponents()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$layout = new PangoCairo\Layout($cairoContext);
var_dump($layout);

$layout->setText('Hello, Παν語!');
$layout->layoutPathForComponents(Pango\RENDER_COMPONENT_NONE);
$layout->layoutPathForComponents(Pango\RENDER_COMPONENT_ALL);

try {
    $layout->layoutPathForComponents(-1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->layoutPathForComponents(Pango\RENDER_COMPONENT_ALL + 1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->layoutPathForComponents();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->layoutPathForComponents(1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->layoutPathForComponents(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
PangoCairo\Layout::layoutPathForComponents(): Argument #1 ($component) must be between 0 and 62 but -1 given
PangoCairo\Layout::layoutPathForComponents(): Argument #1 ($component) must be between 0 and 62 but 63 given
PangoCairo\Layout::layoutPathForComponents() expects exactly 1 argument, 0 given
PangoCairo\Layout::layoutPathForComponents() expects exactly 1 argument, 2 given
PangoCairo\Layout::layoutPathForComponents(): Argument #1 ($component) must be of type int, array given
