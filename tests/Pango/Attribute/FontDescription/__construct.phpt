--TEST--
Pango\Attribute\FontDescription::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\FontDescription as AttrFontDescription;
use Pango\FontDescription;

$fontDescription = new FontDescription("Sans 12");
$attrFontDescription = new AttrFontDescription($fontDescription);
var_dump($attrFontDescription);

try {
    new AttrFontDescription();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new AttrFontDescription($fontDescription, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new AttrFontDescription(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
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
Pango\Attribute\FontDescription::__construct() expects at least 1 argument, 0 given
Pango\Attribute\FontDescription::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\FontDescription::__construct(): Argument #1 ($desc) must be of type Pango\FontDescription, array given
