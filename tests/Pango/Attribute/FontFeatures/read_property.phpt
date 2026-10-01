--TEST--
Pango\Attribute\FontFeatures read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\FontFeatures;

$fontFeatures = new FontFeatures("kern=0");

var_dump($fontFeatures->value);
var_dump($fontFeatures->startIndex);
var_dump($fontFeatures->endIndex);
?>
--EXPECT--
string(6) "kern=0"
int(0)
int(4294967295)
