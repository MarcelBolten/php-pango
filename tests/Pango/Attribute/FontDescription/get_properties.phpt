--TEST--
Pango\Attribute\FontDescriptionAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\FontDescriptionAttribute as AttrFontDescription;
use Pango\FontDescription;

$attrFontDescription = new AttrFontDescription(new FontDescription("Sans 12"));
var_dump($attrFontDescription);
print_r($attrFontDescription);
?>
--EXPECTF--
object(Pango\Attribute\FontDescriptionAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["desc"]=>
  object(Pango\FontDescription)#%d (0) {
  }
}
Pango\Attribute\FontDescriptionAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [desc] => Pango\FontDescription Object
        (
        )

)
