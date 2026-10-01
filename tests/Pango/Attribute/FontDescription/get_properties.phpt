--TEST--
Pango\Attribute\FontDescription get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\FontDescription as AttrFontDescription;
use Pango\FontDescription;

$attrFontDescription = new AttrFontDescription(new FontDescription("Sans 12"));
var_dump($attrFontDescription);
print_r($attrFontDescription);
?>
--EXPECTF--
object(Pango\Attribute\FontDescription)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["desc"]=>
  object(Pango\FontDescription)#%d (0) {
  }
}
Pango\Attribute\FontDescription Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [desc] => Pango\FontDescription Object
        (
        )

)
