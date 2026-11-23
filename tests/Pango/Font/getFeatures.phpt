--TEST--
Pango\Font::getFeatures()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Context;
use Pango\Ft2\FontMap;
use Pango\FontDescription;

$pathToFonts = dirname(__FILE__, 3) . "/assets/fonts";
putenv("FONTCONFIG_FILE=$pathToFonts/DejaVuSans_features.conf");

$fontMap = new FontMap();
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
var_dump($font->getFeatures());

$font = $context->loadFont(new FontDescription("DejaVu Sans 12"));
var_dump($font);
var_dump($font->getFeatures());

try {
    $font->getFeatures(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Ft2\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\FontDescription)#%d (1) {
  ["string-representation"]=>
  string(%d) "%s"
}
object(Pango\Font)#%d (1) {
  ["string-representation"]=>
  string(%d) "%s"
}
array(0) {
}
object(Pango\Font)#%d (1) {
  ["string-representation"]=>
  string(%d) "%s"
}
array(2) {
  [0]=>
  array(5) {
    ["tag"]=>
    int(1818847073)
    ["tag-string"]=>
    string(4) "liga"
    ["value"]=>
    int(0)
    ["start"]=>
    int(0)
    ["end"]=>
    int(%i)
  }
  [1]=>
  array(5) {
    ["tag"]=>
    int(1801810542)
    ["tag-string"]=>
    string(4) "kern"
    ["value"]=>
    int(1)
    ["start"]=>
    int(0)
    ["end"]=>
    int(%i)
  }
}
Pango\Font::getFeatures() expects exactly 0 arguments, 1 given
