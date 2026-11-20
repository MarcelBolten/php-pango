--TEST--
Pango\FontFamily::getFace() for Windows
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

$defaultFace = $family->getFace();
var_dump($defaultFace);

$defaultFace = $family->getFace(null);
var_dump($defaultFace);

$regularFace = $family->getFace("Does not exist");
var_dump($regularFace);

try {
    $family->getFace("Regular\0");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $family->getFace(null, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $family->getFace(array());
} catch (TypeError $e) {
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
object(Pango\FontFace)#%d (0) {
}
NULL
Pango\FontFamily::getFace(): Argument #1 ($name) must not contain NUL bytes
Pango\FontFamily::getFace() expects at most 1 argument, 2 given
Pango\FontFamily::getFace(): Argument #1 ($name) must be of type ?string, array given
