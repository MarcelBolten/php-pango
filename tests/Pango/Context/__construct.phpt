--TEST--
Pango\Context::__construct()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Context;
use Pango\Ft2\FontMap;

$pangoContext = new Context();
var_dump($pangoContext);

$fontMap = new FontMap();
$pathToFonts = dirname(__FILE__, 3) . "/assets/fonts";
$fontMap->addFontFile($pathToFonts . "/DejaVuSans.ttf");
$fontMap->addFontFile($pathToFonts . "/NotoSansJP-Regular.otf");
$fontMap->addFontFile($pathToFonts . "/NotoSans-Regular.ttf");
var_dump($fontMap);
$pangoContextFromFontMap = new Context($fontMap);
var_dump($pangoContextFromFontMap);

try {
    new Context($fontMap, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Context(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Context)#%d (0) {
}
object(Pango\Ft2\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
Pango\Context::__construct() expects at most 1 argument, 2 given
Pango\Context::__construct(): Argument #1 ($fontmap) must be of type ?Pango\FontMap, array given
