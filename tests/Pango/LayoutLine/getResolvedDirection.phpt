--TEST--
Pango\LayoutLine::getResolvedDirection()
--EXTENSIONS--
pango
cairo
--FILE--
<?php
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);

$pangoContext = new Pango\Context($fontMap);
var_dump($pangoContext);

$layout = new Pango\Layout($pangoContext);
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
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
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
