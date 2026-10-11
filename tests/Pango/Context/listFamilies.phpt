--TEST--
Pango\Context::listFamilies()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Ft2\FontMap;
use Pango\Context;

$fontMap = new FontMap();
$pathToFonts = dirname(__FILE__, 3) . "/assets/fonts";
$fontMap->addFontFile($pathToFonts . "/DejaVuSans.ttf");
$fontMap->addFontFile($pathToFonts . "/NotoSansJP-Regular.otf");
$fontMap->addFontFile($pathToFonts . "/NotoSans-Regular.ttf");
var_dump($fontMap);

$context = new Context($fontMap);
var_dump($context);

$families = $context->listFamilies();
var_dump(is_array($families));
var_dump($families[0]);

try {
    $context->listFamilies(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Ft2\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
bool(true)
object(Pango\FontFamily)#%d (1) {
  ["string-representation"]=>
  string(11) "DejaVu Sans"
}
Pango\Context::listFamilies() expects exactly 0 arguments, 1 given
