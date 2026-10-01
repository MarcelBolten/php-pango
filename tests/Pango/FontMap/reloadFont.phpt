--TEST--
Pango\FontMap::reloadFont()
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

$reloadedFont = $fontMap->reloadFont($font, 2.2);
var_dump($reloadedFont);

$reloadedFont = $fontMap->reloadFont($font, 2.2, $context);
var_dump($reloadedFont);

$reloadedFont = $fontMap->reloadFont($font, 2.2, variations: "wght=700");
var_dump($reloadedFont);

try {
    $fontMap->reloadFont($font, 0);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->reloadFont($font, 1, variations: "\0");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->reloadFont();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->reloadFont($font);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->reloadFont($font, 2.2, $context, "wght=700", "extra");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->reloadFont(array(), 2.2);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->reloadFont($font, array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->reloadFont($font, 2.2, array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->reloadFont($font, 2.2, $context, array());
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
object(Pango\Font)#%d (1) {
  ["string-representation"]=>
  string(14) "DejaVu Sans 12"
}
object(Pango\Font)#%d (1) {
  ["string-representation"]=>
  string(14) "DejaVu Sans 12"
}
object(Pango\Font)#%d (1) {
  ["string-representation"]=>
  string(24) "DejaVu Sans 12 @wght=700"
}
Pango\FontMap::reloadFont(): Argument #2 ($scale) must be a positive number
Pango\FontMap::reloadFont(): Argument #4 ($variations) must not contain NUL bytes
Pango\FontMap::reloadFont() expects at least 2 arguments, 0 given
Pango\FontMap::reloadFont() expects at least 2 arguments, 1 given
Pango\FontMap::reloadFont() expects at most 4 arguments, 5 given
Pango\FontMap::reloadFont(): Argument #1 ($font) must be of type Pango\Font, array given
Pango\FontMap::reloadFont(): Argument #2 ($scale) must be of type float, array given
Pango\FontMap::reloadFont(): Argument #3 ($context) must be of type ?Pango\Context, array given
Pango\FontMap::reloadFont(): Argument #4 ($variations) must be of type ?string, array given
