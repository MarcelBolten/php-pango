--TEST--
Pango\GlyphItem get_properties handler
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

$layout->setText("Hello, Παν語!");
$runs = $layout->getLine(0)->getRuns();
foreach(get_object_vars($runs[0]) as $name => $value) {
    echo $name, ": ", get_debug_type($value), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
item: Pango\Item
glyphs: Pango\GlyphString
yOffset: int
startXOffset: int
endXOffset: int
