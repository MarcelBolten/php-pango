--TEST--
PangoCairo\LayoutLine::getRuns()
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

$line = $layout->getLineReadonly(0);
var_dump($line);
var_dump($line->getRuns());

$layout->setWidth(200 * Pango\SCALE);
$layout->setText("Hello, Παν語!\nThis is a new paragraph with more text that will be wrapped.");
var_dump(count($layout->getLine(0)->getRuns()));
var_dump(count($layout->getLine(1)->getRuns()));

try {
    $line->getRuns(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
object(PangoCairo\LayoutLine)#%d (0) {
}
array(0) {
}
int(4)
int(1)
PangoCairo\LayoutLine::getRuns() expects exactly 0 arguments, 1 given
