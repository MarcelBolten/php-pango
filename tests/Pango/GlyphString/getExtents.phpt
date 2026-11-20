--TEST--
Pango\GlyphString::getExtents()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Ft2\FontMap;
use Pango\Context;
use Pango\Layout;

$fontMap = new FontMap();
$pathToFonts = dirname(__FILE__, 3) . "/assets/fonts";
$fontMap->addFontFile($pathToFonts . "/DejaVuSans.ttf");
$fontMap->addFontFile($pathToFonts . "/NotoSansJP-Regular.otf");
$fontMap->addFontFile($pathToFonts . "/NotoSans-Regular.ttf");
var_dump($fontMap);
$context = new Context($fontMap);
var_dump($context);
$layout = new Layout($context);
var_dump($layout);

$font = (new Pango\Context(PangoCairo\FontMap::getDefault()))
    ->loadFont(new Pango\FontDescription("Sans 12"));
var_dump($font);

$layout->setText("Hello, Παν語!");
$glyphString = $layout
    ->getLinesReadonly()[0] // there is only one line
    ->getRuns()[1] // the second run contains 3 Greek characters
    ->glyphs;
var_dump($glyphString->getExtents($font));

try {
    $glyphString->getExtents();
} catch(ArgumentCountError $e) {
    echo $e->getMessage() . PHP_EOL;
}

try {
    $glyphString->getExtents($font, 1);
} catch(ArgumentCountError $e) {
    echo $e->getMessage() . PHP_EOL;
}

try {
    $glyphString->getExtents(array());
} catch(TypeError $e) {
    echo $e->getMessage() . PHP_EOL;
}
?>
--EXPECTF--
object(Pango\Ft2\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
object(Pango\Font)#%d (1) {
  ["string-representation"]=>
  string(%d) "%s"
}
array(2) {
  ["ink"]=>
  object(Pango\Rectangle)#%d (8) {
    ["x"]=>
    int(%i)
    ["y"]=>
    int(%i)
    ["width"]=>
    int(%i)
    ["height"]=>
    int(%i)
    ["ascent"]=>
    int(%i)
    ["descent"]=>
    int(%i)
    ["leftBearing"]=>
    int(%i)
    ["rightBearing"]=>
    int(%i)
  }
  ["logical"]=>
  object(Pango\Rectangle)#%d (8) {
    ["x"]=>
    int(%i)
    ["y"]=>
    int(%i)
    ["width"]=>
    int(%i)
    ["height"]=>
    int(%i)
    ["ascent"]=>
    int(%i)
    ["descent"]=>
    int(%i)
    ["leftBearing"]=>
    int(%i)
    ["rightBearing"]=>
    int(%i)
  }
}
Pango\GlyphString::getExtents() expects exactly 1 argument, 0 given
Pango\GlyphString::getExtents() expects exactly 1 argument, 2 given
Pango\GlyphString::getExtents(): Argument #1 ($font) must be of type Pango\Font, array given
