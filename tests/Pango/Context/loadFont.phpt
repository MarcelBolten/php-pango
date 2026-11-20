--TEST--
Pango\Context::loadFont()
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
var_dump($context->loadFont($fontDesc));

try {
    $context->loadFont();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->loadFont($fontDesc, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->loadFont(array());
} catch (TypeError $e) {
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
Pango\Context::loadFont() expects exactly 1 argument, 0 given
Pango\Context::loadFont() expects exactly 1 argument, 2 given
Pango\Context::loadFont(): Argument #1 ($fontDesc) must be of type Pango\FontDescription, array given
