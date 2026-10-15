--TEST--
Pango\FontMap::addFontFile()
--EXTENSIONS--
pango
--SKIPIF--
<?php
if (version_compare(Pango\version_string(), '1.56.0', '<')) {
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
    $fontMap->addFontFile(__DIR__ . "/Cantarell-VF.otf\0");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    // the expected error message depends on the underlying font system:
    // with fontconfig:
    //     Adding font /wrong/path/Cantarell-VF.otf to fontconfig configuration failed
    // with direct write on windows:
    //     Specified font file '/wrong/path/Cantarell-VF.otf' does not exist
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
Pango\FontMap::addFontFile(): Argument #1 ($file) must not contain NUL bytes
Error adding font file '/wrong/path/Cantarell-VF.otf': %s/wrong/path/Cantarell-VF.otf%s
Pango\FontMap::addFontFile() expects exactly 1 argument, 0 given
Pango\FontMap::addFontFile() expects exactly 1 argument, 2 given
Pango\FontMap::addFontFile(): Argument #1 ($file) must be of type string, array given
