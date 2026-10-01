--TEST--
Pango\FontDescription::betterMatch()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$fontDescRegular = new Pango\FontDescription("Sans Regular 12");
var_dump($fontDescRegular);

$fontDescLight = new Pango\FontDescription("Sans Light 12");
var_dump($fontDescLight);

$fontDescBold = new Pango\FontDescription("Sans Bold 12");
var_dump($fontDescBold);

var_dump($fontDescRegular->betterMatch($fontDescLight));
var_dump($fontDescRegular->betterMatch($fontDescLight, $fontDescBold));

try {
    $fontDescRegular->betterMatch();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDescRegular->betterMatch($fontDescLight, $fontDescBold, "extra");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDescRegular->betterMatch(array(), $fontDescBold);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDescRegular->betterMatch($fontDescLight, array());
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
bool(true)
bool(true)
Pango\FontDescription::betterMatch() expects at least 1 argument, 0 given
Pango\FontDescription::betterMatch() expects at most 2 arguments, 3 given
Pango\FontDescription::betterMatch(): Argument #1 ($candidate) must be of type Pango\FontDescription, array given
Pango\FontDescription::betterMatch(): Argument #2 ($currentBest) must be of type ?Pango\FontDescription, array given
