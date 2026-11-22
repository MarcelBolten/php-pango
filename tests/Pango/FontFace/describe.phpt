--TEST--
Pango\FontFace::describe()
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

$family = $fontMap->getFamily("Sans");
var_dump($family);

$defaultFace = $family->getFace(null);
var_dump($defaultFace);
var_dump($defaultFace->describe());

try {
    $defaultFace->describe(1);
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
object(Pango\FontFace)#%d (1) {
  ["string-representation"]=>
  string(%d) "%s"
}
object(Pango\FontDescription)#%d (0) {
}
Pango\FontFace::describe() expects exactly 0 arguments, 1 given
