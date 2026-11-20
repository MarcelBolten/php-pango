--TEST--
Pango\FontFace::listSizes()
--EXTENSIONS--
pango
--SKIPIF--
<?php
if (strtolower(PHP_OS_FAMILY) === 'windows') {
    die('xfail - This test is expected to fail on Windows');
}
?>
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

$defaultFace = $family->getFace();
var_dump($defaultFace);
var_dump($defaultFace->listSizes());

$bitmapFamily = $fontMap->getFamily("Noto Color Emoji");
$bitmapFace = $bitmapFamily->getFace("Regular");
var_dump($bitmapFace->listSizes());

try {
    $defaultFace->listSizes(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Ft2\FontMap)#%d (0) {
}
object(Pango\FontFamily)#%d (0) {
}
object(Pango\FontFace)#%d (0) {
}
array(0) {
}
array(1) {
  [0]=>
  int(%d)
}
Pango\FontFace::listSizes() expects exactly 0 arguments, 1 given
