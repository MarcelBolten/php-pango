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
    new AttrLanguage($language, -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new AttrLanguage($language, PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new AttrLanguage($language, endIndex: -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new AttrLanguage($language, endIndex: PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new AttrLanguage($language, 30, 20);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

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
Pango\Attribute\Language::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but -1 given
Pango\Attribute\Language::__construct(): Argument #2 ($startIndex) must be between 0 and 4294967295 but 9223372036854775807 given
Pango\Attribute\Language::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but -1 given
Pango\Attribute\Language::__construct(): Argument #3 ($endIndex) must be greater than 0 and at most 4294967295, but 9223372036854775807 given
Pango\Attribute\Language::__construct(): Argument #3 ($endIndex) must be greater than 30 and at most 4294967295, but 20 given
Pango\Attribute\Language::__construct() expects at least 1 argument, 0 given
Pango\Attribute\Language::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\Language::__construct(): Argument #1 ($value) must be of type Pango\Language, array given
