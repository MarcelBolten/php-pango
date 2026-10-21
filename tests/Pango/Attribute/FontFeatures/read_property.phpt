--TEST--
Pango\Attribute\FontFeaturesAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\FontFeaturesAttribute;

$fontFeatures = new FontFeaturesAttribute("kern=0");

var_dump($fontFeatures->value);
var_dump($fontFeatures->startIndex);
var_dump($fontFeatures->endIndex);
?>
--EXPECT--
string(6) "kern=0"
int(0)
int(4294967295)
