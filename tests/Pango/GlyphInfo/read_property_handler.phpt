--TEST--
Pango\GlyphInfo read property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Ft2\FontMap;
use Pango\Context;
use Pango\Layout;

$fontMap = new FontMap();
$pathToFonts = dirname(__FILE__, 3) . "/assets/fonts";
$fontMap->addFontFile($pathToFonts . "/DejaVuSans.ttf");
$fontMap->addFontFile($pathToFonts . "/NotoSansJP-Regular.otf");
$fontMap->addFontFile($pathToFonts . "/NotoSans-Regular.ttf");
var_dump($fontMap);
$context = new Context($fontMap);
var_dump($context);
$layout = new Layout($context);
var_dump($layout);

$layout->setText("Hello, Παν語!");
foreach ($layout->getLinesReadonly() as $line) {
    $glyphs = $line->getRuns()[1]->glyphs->glyphs[0];
    var_dump($glyphs->glyph);
    var_dump($glyphs->geometry);
    var_dump($glyphs->attributes);
}
?>
--EXPECTF--
object(Pango\Ft2\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
int(%d)
object(Pango\GlyphGeometry)#%d (3) {
  ["width"]=>
  int(%i)
  ["xOffset"]=>
  int(%i)
  ["yOffset"]=>
  int(%i)
}
object(Pango\GlyphVisAttr)#%d (2) {
  ["isClusterStart"]=>
  bool(true)
  ["isColor"]=>
  bool(false)
}
