--TEST--
Pango\Font::getFeatures()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
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
$fontDesc = new FontDescription("DejaVu Sans 12");
var_dump($fontDesc);
$font = $context->loadFont($fontDesc);
var_dump($font);
var_dump($font->getFeatures());
// TODO: test getFeatures() with font that has OpenType features

try {
    $font->getFeatures(1);
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
  string(14) "DejaVu Sans 12"
}
array(0) {
}
Pango\Font::getFeatures() expects exactly 0 arguments, 1 given
