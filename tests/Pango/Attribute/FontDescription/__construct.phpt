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
    new AttrFontDescription($fontDescription, -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new AttrFontDescription($fontDescription, PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new AttrFontDescription($fontDescription, endIndex: -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new AttrFontDescription($fontDescription, endIndex: PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new AttrFontDescription($fontDescription, 30, 20);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

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
Pango\Attribute\FontDescription::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but -1 given
Pango\Attribute\FontDescription::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but 9223372036854775807 given
Pango\Attribute\FontDescription::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but -1 given
Pango\Attribute\FontDescription::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but 9223372036854775807 given
Pango\Attribute\FontDescription::__construct(): Argument #3 ($endIndex) must be greater than 30 and at most 4294967295, but 20 given
Pango\Attribute\FontDescription::__construct() expects at least 1 argument, 0 given
Pango\Attribute\FontDescription::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\FontDescription::__construct(): Argument #1 ($desc) must be of type Pango\FontDescription, array given
