--TEST--
Pango\Attribute\FontDescription object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\FontDescription as AttrFontDescription;
use Pango\FontDescription;

$attrFontDescription = new AttrFontDescription(new FontDescription("Sans 8"));
$attrFontDescription->desc = new FontDescription("Sans-Serif 14");
$attrFontDescription->startIndex = 13;
$attrFontDescription->endIndex = 42;

var_dump($attrFontDescription->desc);
var_dump($attrFontDescription->startIndex);
var_dump($attrFontDescription->endIndex);

try {
    $attrFontDescription->desc = 1;
}
catch (Throwable $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
int(13)
int(42)
Cannot assign int to property Pango\Attribute\FontDescription::$desc of type Pango\FontDescription
