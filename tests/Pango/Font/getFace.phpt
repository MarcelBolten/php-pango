--TEST--
Pango\Font::getFace()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Context;
use Pango\Ft2\FontMap;
use Pango\FontDescription;

$fontMap = new FontMap();
$pathToFonts = dirname(__FILE__, 3) . "/assets/fonts";
$fontMap->addFontFile($pathToFonts . "/DejaVuSans.ttf");
$fontMap->addFontFile($pathToFonts . "/NotoSansJP-Regular.otf");
$fontMap->addFontFile($pathToFonts . "/NotoSans-Regular.ttf");
var_dump($fontMap);
$context = new Context($fontMap);
var_dump($context);
$fontDesc = new FontDescription("Sans 12");
var_dump($fontDesc);
$font = $context->loadFont($fontDesc);
var_dump($font);
var_dump($font->getFace());

try {
    $font->getFace(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Ft2\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\FontDescription)#%d (0) {
}
object(Pango\Font)#%d (1) {
  ["string-representation"]=>
  string(%d) "%s"
}
object(Pango\FontFace)#%d (1) {
  ["string-representation"]=>
  string(%d) "%s"
}
Pango\Font::getFace() expects exactly 0 arguments, 1 given
