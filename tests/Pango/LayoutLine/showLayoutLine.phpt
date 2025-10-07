--TEST--
Pango\LayoutLine::showLayoutLine()
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
$line->showLayoutLine();

$layout->setWidth(200 * Pango\Pango::SCALE);
$layout->setText("Hello, Παν語!\nThis is a new paragraph with more text that will be wrapped.");
var_dump($layout->getLineCount());
foreach ($layout->getLines() as $line) {
    $line->showLayoutLine();
}

$line->showLayoutLine($cairoContext);

try {
    $line->showLayoutLine($cairoContext, 2);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $line->showLayoutLine(array());
} catch (TypeError $e) {
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
int(4)
Pango\LayoutLine::showLayoutLine() expects at most 1 argument, 2 given
Pango\LayoutLine::showLayoutLine(): Argument #1 ($context) must be of type Cairo\Context, array given
