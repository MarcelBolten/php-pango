--TEST--
Pango\FontSet::getFontForCodepoint()
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
$fontDesc = new FontDescription('Sans 12');
var_dump($fontDesc);
$language = new Language('en');
var_dump($language);
$fontSet = $context->loadFontSet($fontDesc, $language);
var_dump($fontSet);
var_dump($fontSet->getFontForCodepoint(mb_ord('🐘', 'UTF-8')));

try {
    $fontSet->getFontForCodepoint();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontSet->getFontForCodepoint(ord('A'), 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontSet->getFontForCodepoint(array());
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
object(Pango\Font)#%d (1) {
  ["string-representation"]=>
  string(19) "Noto Color Emoji 12"
}
Pango\FontSet::getFontForCodepoint() expects exactly 1 argument, 0 given
Pango\FontSet::getFontForCodepoint() expects exactly 1 argument, 2 given
Pango\FontSet::getFontForCodepoint(): Argument #1 ($codepoint) must be of type int, array given
