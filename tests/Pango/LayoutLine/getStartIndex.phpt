--TEST--
Pango\LayoutLine::getStartIndex()
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
var_dump($line->getStartIndex());

$layout->setText("Hello,\nΠαν語!\n");
foreach ($layout->getLines() as $line) {
    var_dump($line->getStartIndex());
}

try {
    $line->getStartIndex(1);
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
int(0)
int(7)
int(18)
Pango\LayoutLine::getStartIndex() expects exactly 0 arguments, 1 given
