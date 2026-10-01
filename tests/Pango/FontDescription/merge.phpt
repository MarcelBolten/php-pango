--TEST--
Pango\FontDescription::merge()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$fontDesc = new Pango\FontDescription("Sans Regular 12");
var_dump($fontDesc);

$fontDescLight = new Pango\FontDescription("Sans Italic Light 16");
var_dump($fontDescLight);

var_dump($fontDesc->merge($fontDescLight));
var_dump($fontDescLight->getStyle());

var_dump($fontDesc->merge($fontDescLight, replaceExisting: true));
var_dump($fontDescLight->getSize());

var_dump($fontDesc->merge(NULL));

try {
    $fontDesc->merge();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDesc->merge($fontDescLight, true, "extra");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDesc->merge(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDesc->merge($fontDescLight, array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
object(Pango\FontDescription)#%d (0) {
}
object(Pango\FontDescription)#%d (0) {
}
enum(Pango\Style::Italic)
object(Pango\FontDescription)#%d (0) {
}
int(16384)
object(Pango\FontDescription)#%d (0) {
}
Pango\FontDescription::merge() expects at least 1 argument, 0 given
Pango\FontDescription::merge() expects at most 2 arguments, 3 given
Pango\FontDescription::merge(): Argument #1 ($other) must be of type ?Pango\FontDescription, array given
Pango\FontDescription::merge(): Argument #2 ($replaceExisting) must be of type bool, array given
