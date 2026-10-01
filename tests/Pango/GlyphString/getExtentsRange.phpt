--TEST--
Pango\GlyphString::getExtentsRange()
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
var_dump($glyphString->getExtentsRange(
    start: 0,
    end: 3,
    font: $font,
));

try {
    $glyphString->getExtentsRange(-1, 2, $font);
} catch(ValueError $e) {
    echo $e->getMessage() . PHP_EOL;
}

try {
    $glyphString->getExtentsRange(4, 2, $font);
} catch(ValueError $e) {
    echo $e->getMessage() . PHP_EOL;
}

try {
    $glyphString->getExtentsRange(0, -1, $font);
} catch(ValueError $e) {
    echo $e->getMessage() . PHP_EOL;
}

try {
    $glyphString->getExtentsRange(0, 4, $font);
} catch(ValueError $e) {
    echo $e->getMessage() . PHP_EOL;
}

try {
    $glyphString->getExtentsRange(2, 2, $font);
} catch(ValueError $e) {
    echo $e->getMessage() . PHP_EOL;
}

try {
    $glyphString->getExtentsRange();
} catch(ArgumentCountError $e) {
    echo $e->getMessage() . PHP_EOL;
}

try {
    $glyphString->getExtentsRange(0);
} catch(ArgumentCountError $e) {
    echo $e->getMessage() . PHP_EOL;
}

try {
    $glyphString->getExtentsRange(0, 1);
} catch(ArgumentCountError $e) {
    echo $e->getMessage() . PHP_EOL;
}

try {
    $glyphString->getExtentsRange(0, 1, $font, 3);
} catch(ArgumentCountError $e) {
    echo $e->getMessage() . PHP_EOL;
}

try {
    $glyphString->getExtentsRange(array(), 2, $font);
} catch(TypeError $e) {
    echo $e->getMessage() . PHP_EOL;
}

try {
    $glyphString->getExtentsRange(0, array(), $font);
} catch(TypeError $e) {
    echo $e->getMessage() . PHP_EOL;
}

try {
    $glyphString->getExtentsRange(0, 2, array());
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
Pango\GlyphString::getExtentsRange(): Argument #1 ($start) must be between 0 and 3 but -1 given
Pango\GlyphString::getExtentsRange(): Argument #1 ($start) must be between 0 and 3 but 4 given
Pango\GlyphString::getExtentsRange(): Argument #2 ($end) must be between 0 and 3 but -1 given
Pango\GlyphString::getExtentsRange(): Argument #2 ($end) must be between 0 and 3 but 4 given
Pango\GlyphString::getExtentsRange(): Argument #2 ($end) must be greater than argument #1 ($start) 2 but 2 given
Pango\GlyphString::getExtentsRange() expects exactly 3 arguments, 0 given
Pango\GlyphString::getExtentsRange() expects exactly 3 arguments, 1 given
Pango\GlyphString::getExtentsRange() expects exactly 3 arguments, 2 given
Pango\GlyphString::getExtentsRange() expects exactly 3 arguments, 4 given
Pango\GlyphString::getExtentsRange(): Argument #1 ($start) must be of type int, array given
Pango\GlyphString::getExtentsRange(): Argument #2 ($end) must be of type int, array given
Pango\GlyphString::getExtentsRange(): Argument #3 ($font) must be of type Pango\Font, array given
