--TEST--
Pango\FontMap::listFamilies()
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
$families = $fontMap->listFamilies();
var_dump(is_array($families));
var_dump($families[0]);

try {
    $fontMap->listFamilies(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Ft2\FontMap)#%d (0) {
}
bool(true)
object(Pango\FontFamily)#%d (0) {
}
Pango\FontMap::listFamilies() expects exactly 0 arguments, 1 given
