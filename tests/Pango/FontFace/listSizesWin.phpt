--TEST--
Pango\FontFace::listSizes() for Windows
--EXTENSIONS--
pango
--FILE--
<?php
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);

$family = $fontMap->listFamilies()[0];
var_dump($family);

$defaultFace = $family->getFace();
var_dump($defaultFace);
var_dump($defaultFace->listSizes());

try {
    $defaultFace->listSizes(1);
} catch (ArgumentCountError $e) {
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
array(0) {
}
Pango\FontFace::listSizes() expects exactly 0 arguments, 1 given
