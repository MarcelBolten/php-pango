--TEST--
Pango\GlyphString get_properties handler
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
foreach ($layout->getLinesReadonly() as $line) {
    $runs = $line->getRuns();
    foreach(get_object_vars($runs[1]->glyphs) as $name => $value) {
        echo $name, ": ", get_debug_type($value);
        echo "\n";
    }
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
numGlyphs: int
glyphs: array
