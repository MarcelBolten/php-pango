--TEST--
PangoCairo\FontMap::newForFontType()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
use PangoCairo\FontMap;
use Cairo\FontType;

try {
    FontMap::newForFontType(FontType::Toy);
} catch (Pango\Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}

var_dump(FontMap::newForFontType(FontType::FT));

try {
    FontMap::newForFontType();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    FontMap::newForFontType(FontType::Toy, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    FontMap::newForFontType(array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
?>
--EXPECTF--
Could not create new PangoCairo\FontMap for Cairo\FontType::Toy
object(PangoCairo\FontMap)#%d (0) {
}
PangoCairo\FontMap::newForFontType() expects exactly 1 argument, 0 given
PangoCairo\FontMap::newForFontType() expects exactly 1 argument, 2 given
PangoCairo\FontMap::newForFontType(): Argument #1 ($type) must be of type Cairo\FontType, array given
