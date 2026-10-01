--TEST--
Pango\Attribute\FontFeatures object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\FontFeatures;

$fontFeatures = new FontFeatures("kern=0");
$fontFeatures->value = "kern=9";
$fontFeatures->startIndex = 13;
$fontFeatures->endIndex = 42;

var_dump($fontFeatures->value);
var_dump($fontFeatures->startIndex);
var_dump($fontFeatures->endIndex);
?>
--EXPECT--
string(6) "kern=9"
int(13)
int(42)
