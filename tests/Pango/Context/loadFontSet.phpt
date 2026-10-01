--TEST--
Pango\Context::loadFontSet()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Context;
use PangoCairo\FontMap;
use Pango\FontDescription;
use Pango\Language;

$fontMap = FontMap::getDefault();
var_dump($fontMap);
$context = new Context($fontMap);
var_dump($context);
$fontDesc = new FontDescription("Sans 12");
var_dump($fontDesc);
$language = new Language("en");
var_dump($language);
var_dump($context->loadFontSet($fontDesc, $language));

try {
    $context->loadFontSet();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->loadFontSet($fontDesc, $language, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->loadFontSet(array(), $language);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->loadFontSet($fontDesc, array());
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
Pango\Context::loadFontSet() expects exactly 2 arguments, 0 given
Pango\Context::loadFontSet() expects exactly 2 arguments, 3 given
Pango\Context::loadFontSet(): Argument #1 ($fontDesc) must be of type Pango\FontDescription, array given
Pango\Context::loadFontSet(): Argument #2 ($language) must be of type Pango\Language, array given
