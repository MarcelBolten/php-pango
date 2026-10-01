--TEST--
Pango\Attribute\Language get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Language as AttrLanguage;
use Pango\Language;

$attrLanguage = new AttrLanguage(new Language("en"));
var_dump($attrLanguage);
print_r($attrLanguage);
?>
--EXPECTF--
object(Pango\Attribute\Language)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  object(Pango\Language)#%d (1) {
    ["string-representation"]=>
    string(2) "en"
  }
}
Pango\Attribute\Language Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\Language Object
        (
            [string-representation] => en
        )

)
