--TEST--
Pango\LayoutLine::getRuns()
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
var_dump($line->getRuns());

$layout->setText("Hello, Παν語!");
foreach ($layout->getLinesReadonly() as $line) {
    var_dump($line instanceof Pango\LayoutLine);
    foreach ($line->getRuns() as $run) {
      var_dump($run instanceof Pango\GlyphItem);
    }
}

try {
    $line->getRuns(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
array(0) {
}
bool(true)
bool(true)
bool(true)
bool(true)
bool(true)
Pango\LayoutLine::getRuns() expects exactly 0 arguments, 1 given
