--TEST--
Pango\FontFamily::listFaces()
--EXTENSIONS--
pango
cairo
--FILE--
<?php
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);

$family = $fontMap->listFamilies()[0];
var_dump($family);

$faces = $family->listFaces();
var_dump(is_array($faces));
var_dump($faces[0]);

try {
    $family->listFaces(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\FontFamily)#%d (0) {
}
bool(true)
object(Pango\FontFace)#%d (0) {
}
Pango\FontFamily::listFaces() expects exactly 0 arguments, 1 given
