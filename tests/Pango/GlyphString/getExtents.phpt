--TEST--
Pango\GlyphString::getExtents()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$layout = new PangoCairo\Layout($cairoContext);
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
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
object(Pango\Font)#%d (1) {
  ["string-representation"]=>
  string(14) "DejaVu Sans 12"
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
