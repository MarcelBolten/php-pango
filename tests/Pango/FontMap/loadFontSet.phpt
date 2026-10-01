--TEST--
Pango\FontMap::loadFontSet()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
use Pango\FontDescription;
use Pango\Language;
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);
$context = $fontMap->createContext();
var_dump($context);
$fontDesc = new FontDescription("Sans 12");
var_dump($fontDesc);
$language = new Language("en");
var_dump($language);
$fontSet = $fontMap->loadFontSet($context, $fontDesc, $language);
var_dump($fontSet);

try {
    $fontMap->loadFontSet();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->loadFontSet($context);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->loadFontSet($context, $fontDesc);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->loadFontSet($context, $fontDesc, $language, 'extra');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->loadFontSet(array(), $fontDesc, $language);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->loadFontSet($context, array(), $language);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->loadFontSet($context, $fontDesc, array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\FontDescription)#%d (0) {
}
object(Pango\Language)#%d (1) {
  ["string-representation"]=>
  string(2) "en"
}
object(Pango\FontSet)#%d (0) {
}
Pango\FontMap::loadFontSet() expects exactly 3 arguments, 0 given
Pango\FontMap::loadFontSet() expects exactly 3 arguments, 1 given
Pango\FontMap::loadFontSet() expects exactly 3 arguments, 2 given
Pango\FontMap::loadFontSet() expects exactly 3 arguments, 4 given
Pango\FontMap::loadFontSet(): Argument #1 ($context) must be of type Pango\Context, array given
Pango\FontMap::loadFontSet(): Argument #2 ($desc) must be of type Pango\FontDescription, array given
Pango\FontMap::loadFontSet(): Argument #3 ($language) must be of type Pango\Language, array given
