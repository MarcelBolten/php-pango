--TEST--
Pango\LayoutLine::getLength()
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
$empty_line_length = $line->getLength();
var_dump($empty_line_length);

$layout->setText("Hello, Παν語!");
$line = $layout->getLineReadonly(0);
var_dump($line);
$line_length = $line->getLength();
var_dump($line_length);

try {
    $line->getLength(1);
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
int(0)
object(Pango\LayoutLine)#%d (0) {
}
int(17)
Pango\LayoutLine::getLength() expects exactly 0 arguments, 1 given
