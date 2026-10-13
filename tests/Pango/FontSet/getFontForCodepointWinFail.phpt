--TEST--
Pango\FontSet::getFontForCodepoint() failing on Windows ci runner
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
if (strtolower(PHP_OS_FAMILY) !== 'windows') {
    die('skip - This test is for Windows only');
}
if (strtolower(PHP_OS_FAMILY) === 'windows') {
    die('xfail - This test is expected to fail on Windows');
}
// TODO: investigate why this test fails on Windows with
// (process:5008): Pango-CRITICAL **: pango_font_describe: assertion 'font != NULL' failed
// (process:5008): Pango-CRITICAL **: pango_font_description_to_string: assertion 'desc != NULL' failed
// Termsig=-1073741819
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
var_dump($fontSet->getFontForCodepoint(128024)); // mb_ord('🐘', 'UTF-8')

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
  string(%d) "%s"
}
object(Pango\FontSet)#%d (0) {
}
object(Pango\Font)#%d (1) {
  ["string-representation"]=>
  string(%d) "%s"
}
Pango\FontSet::getFontForCodepoint() expects exactly 1 argument, 0 given
Pango\FontSet::getFontForCodepoint() expects exactly 1 argument, 2 given
Pango\FontSet::getFontForCodepoint(): Argument #1 ($codepoint) must be of type int, array given
