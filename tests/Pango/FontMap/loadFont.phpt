--TEST--
Pango\FontMap::loadFont()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
use PangoCairo\FontMap;
use Pango\FontDescription;

$fontMap = FontMap::getDefault();
var_dump($fontMap);
$context = $fontMap->createContext();
var_dump($context);
$fontDesc = new FontDescription("Sans 12");
var_dump($fontDesc);
$font = $fontMap->loadFont($context, $fontDesc);
var_dump($font);

try {
    $fontMap->loadFont();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->loadFont($context);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->loadFont($context, $fontDesc, 'extra');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->loadFont(array(), $fontDesc);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->loadFont($context, array());
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
Pango\FontMap::loadFont() expects exactly 2 arguments, 0 given
Pango\FontMap::loadFont() expects exactly 2 arguments, 1 given
Pango\FontMap::loadFont() expects exactly 2 arguments, 3 given
Pango\FontMap::loadFont(): Argument #1 ($context) must be of type Pango\Context, array given
Pango\FontMap::loadFont(): Argument #2 ($desc) must be of type Pango\FontDescription, array given
