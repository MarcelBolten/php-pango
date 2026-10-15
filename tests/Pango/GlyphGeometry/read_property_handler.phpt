--TEST--
Pango\GlyphInfo read property handler
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
foreach ($layout->getLinesReadonly() as $line) {
    $geom = $line->getRuns()[1]->glyphs->glyphs[0]->geometry;
    var_dump($geom->width);
    var_dump($geom->xOffset);
    var_dump($geom->yOffset);
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
int(%i)
int(%i)
int(%i)
