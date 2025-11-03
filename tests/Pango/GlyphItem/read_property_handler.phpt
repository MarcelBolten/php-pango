--TEST--
Pango\GlyphItem read property handler
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
    $runs = $line->getRuns();
    var_dump($runs[0]->item instanceof Pango\Item);
    var_dump($runs[0]->glyphs instanceof Pango\GlyphString);
    var_dump($runs[0]->yOffset);
    var_dump($runs[0]->startXOffset);
    var_dump($runs[0]->endXOffset);
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
bool(true)
bool(true)
int(0)
int(0)
int(0)
