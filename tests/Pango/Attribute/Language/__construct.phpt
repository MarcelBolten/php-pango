--TEST--
Pango\Attribute\Language::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Language as AttrLanguage;
use Pango\Language;

$language = new Language("en");
$attrLanguage = new AttrLanguage($language);
var_dump($attrLanguage);

try {
    new AttrLanguage();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new AttrLanguage($language, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new AttrLanguage(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
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
Pango\Attribute\Language::__construct() expects at least 1 argument, 0 given
Pango\Attribute\Language::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\Language::__construct(): Argument #1 ($value) must be of type Pango\Language, array given
