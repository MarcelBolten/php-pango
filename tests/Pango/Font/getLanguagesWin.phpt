--TEST--
Pango\Font::getLanguages()
--EXTENSIONS--
pango
--SKIPIF--
<?php
if (strtolower(PHP_OS_FAMILY) !== 'windows') {
    die('skip - This test is for Windows only');
}
?>
--FILE--
<?php
use Pango\Context;
use PangoCairo\FontMap;
use Pango\FontDescription;

$fontMap = FontMap::getDefault();
var_dump($fontMap);
$context = new Context($fontMap);
var_dump($context);
$fontDesc = new FontDescription("Sans 12");
var_dump($fontDesc);
$font = $context->loadFont($fontDesc);
var_dump($font);
// the direct write backend on Windows typically does not provide language information
var_dump($font->getLanguages());

try {
    $font->getLanguages(1);
} catch (ArgumentCountError $e) {
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
object(Pango\Font)#%d (1) {
  ["string-representation"]=>
  string(%d) "%s"
}
array(0) {
}
Pango\Font::getLanguages() expects exactly 0 arguments, 1 given
