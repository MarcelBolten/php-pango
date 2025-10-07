--TEST--
Pango\LayoutLine::getResolvedDirection()
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

$line = $layout->getLineReadonly(0);
var_dump($line);
var_dump($line->getResolvedDirection());

$layout->setText("Hello, Παν語!");
$line = $layout->getLineReadonly(0);
var_dump($line);
var_dump($line->getResolvedDirection());

$layout->setText("مرحبا");
$line = $layout->getLineReadonly(0);
var_dump($line);
var_dump($line->getResolvedDirection());

try {
    $line->getResolvedDirection(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
object(Pango\LayoutLine)#%d (0) {
}
enum(Pango\Direction::LTR)
object(Pango\LayoutLine)#%d (0) {
}
enum(Pango\Direction::LTR)
object(Pango\LayoutLine)#%d (0) {
}
enum(Pango\Direction::RTL)
Pango\LayoutLine::getResolvedDirection() expects exactly 0 arguments, 1 given
