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
$glyphString = $layout
    ->getLinesReadonly()[0] // there is only one line
    ->getRuns()[1] // the second run contains 3 Greek characters
    ->glyphs;
    foreach(get_object_vars($glyphString) as $propName => $propValue) {
        echo $propName, ": ", get_debug_type($propValue);
        echo "\n";
    }
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
numGlyphs: int
glyphs: array
