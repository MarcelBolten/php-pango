--TEST--
Pango\FontFamily::getFace()
--EXTENSIONS--
pango
cairo
--FILE--
<?php
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);

$family = $fontMap->getFamily("Sans");
var_dump($family);

$defaultFace = $family->getFace();
var_dump($defaultFace);

$defaultFace = $family->getFace(null);
var_dump($defaultFace);

$regularFace = $family->getFace("Regular");
var_dump($regularFace);

$regularFace = $family->getFace("Does not exist");
var_dump($regularFace);

try {
    $family->getFace(null, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $family->getFace(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\FontFamily)#%d (0) {
}
object(Pango\FontFace)#%d (0) {
}
object(Pango\FontFace)#%d (0) {
}
object(Pango\FontFace)#%d (0) {
}
NULL
Pango\FontFamily::getFace() expects at most 1 argument, 2 given
Pango\FontFamily::getFace(): Argument #1 ($name) must be of type ?string, array given
