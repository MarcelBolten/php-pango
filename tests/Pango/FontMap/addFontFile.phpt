--TEST--
Pango\FontMap::addFontFile()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
if (version_compare(Pango\Pango::versionString(), '1.56.0', '<')) {
    die("skip Pango version < 1.56.0");
}
?>
--FILE--
<?php
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);
var_dump($fontMap->addFontFile(__DIR__ . "/Cantarell-VF.otf"));

try {
    $fontMap->addFontFile("/wrong/path/Cantarell-VF.otf");
} catch (Pango\Exception $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->addFontFile();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->addFontFile('wrong', 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->addFontFile(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
bool(true)
Error adding font file '/wrong/path/Cantarell-VF.otf': Adding font /wrong/path/Cantarell-VF.otf to fontconfig configuration failed
Pango\FontMap::addFontFile() expects exactly 1 argument, 0 given
Pango\FontMap::addFontFile() expects exactly 1 argument, 2 given
Pango\FontMap::addFontFile(): Argument #1 ($file) must be of type string, array given
