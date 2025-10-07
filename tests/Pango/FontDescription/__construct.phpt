--TEST--
Pango\FontDescription::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$fontDesc = new Pango\FontDescription();
var_dump($fontDesc);

$fontDesc = new Pango\FontDescription("Sans 12");
var_dump($fontDesc);

try {
    $fontDesc = new Pango\FontDescription("1", "2");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
object(Pango\FontDescription)#%d (0) {
}
Pango\FontDescription::__construct() expects at most 1 argument, 2 given
