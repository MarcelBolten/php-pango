--TEST--
Pango\LayoutLine::getHeight()
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
$empty_line_height = $line->getHeight();
var_dump($empty_line_height);

$layout->setMarkup("Hello, <span size='x-large'>Παν語!</span>");
$line = $layout->getLineReadonly(0);
var_dump($line);
$line_height = $line->getHeight();
var_dump($line_height);
var_dump($line_height > $empty_line_height);

try {
    $line->getHeight(1);
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
int(%d)
object(Pango\LayoutLine)#%d (0) {
}
int(%d)
bool(true)
Pango\LayoutLine::getHeight() expects exactly 0 arguments, 1 given
