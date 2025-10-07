--TEST--
Pango\Layout::setEllipsize()
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

var_dump($layout->getEllipsize());

$layout->setEllipsize(Pango\EllipsizeMode::Middle);
var_dump($layout->getEllipsize());

try {
    $layout->setEllipsize();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setEllipsize(Pango\EllipsizeMode::End, 'wrong');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setEllipsize('middle');
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
enum(Pango\EllipsizeMode::None)
enum(Pango\EllipsizeMode::Middle)
Pango\Layout::setEllipsize() expects exactly 1 argument, 0 given
Pango\Layout::setEllipsize() expects exactly 1 argument, 2 given
Pango\Layout::setEllipsize(): Argument #1 ($mode) must be of type Pango\EllipsizeMode, string given
