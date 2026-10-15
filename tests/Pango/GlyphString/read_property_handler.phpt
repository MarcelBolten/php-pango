--TEST--
Pango\GlyphString read property handler
--EXTENSIONS--
pango
cairo
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

var_dump($glyphString->numGlyphs);
var_dump(is_array($glyphString->glyphs));

?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
int(3)
bool(true)
