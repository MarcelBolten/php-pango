--TEST--
Pango\Layout::setAlignment()
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

var_dump($layout->getAlignment());

$layout->setAlignment(Pango\Alignment::Center);
var_dump($layout->getAlignment());

try {
    $layout->setAlignment();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setAlignment(Pango\Alignment::Right, 'wrong');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setAlignment('left');
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
enum(Pango\Alignment::Left)
enum(Pango\Alignment::Center)
Pango\Layout::setAlignment() expects exactly 1 argument, 0 given
Pango\Layout::setAlignment() expects exactly 1 argument, 2 given
Pango\Layout::setAlignment(): Argument #1 ($alignment) must be of type Pango\Alignment, string given
