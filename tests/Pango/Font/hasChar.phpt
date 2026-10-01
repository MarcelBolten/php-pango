--TEST--
Pango\Font::hasChar()
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
$fontDesc = new FontDescription("Sans 12");
var_dump($fontDesc);
$font = $context->loadFont($fontDesc);
var_dump($font);
var_dump($font->hasChar('あ'));
var_dump($font->hasChar('a'));

try {
    $font->hasChar("\0あ");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $font->hasChar('あ', 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $font->hasChar(array());
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
object(Pango\Font)#%d (1) {
  ["string-representation"]=>
  string(14) "DejaVu Sans 12"
}
bool(false)
bool(true)
Pango\Font::hasChar(): Argument #1 ($char) must not contain NUL bytes
Pango\Font::hasChar() expects exactly 1 argument, 2 given
Pango\Font::hasChar(): Argument #1 ($char) must be of type string, array given
