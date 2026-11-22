--TEST--
Pango\FontFamily::listFaces()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Ft2\FontMap;

$fontMap = new FontMap();
$pathToFonts = dirname(__FILE__, 3) . "/assets/fonts";
$fontMap->addFontFile($pathToFonts . "/DejaVuSans.ttf");
$fontMap->addFontFile($pathToFonts . "/NotoSansJP-Regular.otf");
$fontMap->addFontFile($pathToFonts . "/NotoSans-Regular.ttf");
var_dump($fontMap);

$family = $fontMap->listFamilies()[0];
var_dump($family);

$faces = $family->listFaces();
var_dump(is_array($faces));
var_dump($faces[0]);

try {
    $family->listFaces(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Ft2\FontMap)#%d (0) {
}
object(Pango\FontFamily)#%d (1) {
  ["string-representation"]=>
  string(%d) "%s"
}
bool(true)
object(Pango\FontFace)#%d (0) {
}
Pango\FontFamily::listFaces() expects exactly 0 arguments, 1 given
