--TEST--
Pango\GlyphString read property handler
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

$layout->setText("Hello, Παν語!");
foreach ($layout->getLinesReadonly() as $line) {
    $glyphs = $line->getRuns()[1]->glyphs;
    var_dump($glyphs->numGlyphs);
    var_dump(is_array($glyphs->glyphs));
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
int(3)
bool(true)
