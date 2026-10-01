--TEST--
Pango\Language::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Language;

$language = new Language("en");
var_dump($language);

// $language = new Language("not a valid language tag");

try {
    new Language("en\0");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Language();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Language("en", 2);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Language(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
object(Pango\Language)#1 (1) {
  ["string-representation"]=>
  string(2) "en"
}
Pango\Language::__construct(): Argument #1 ($language) must not contain NUL bytes
Pango\Language::__construct() expects exactly 1 argument, 0 given
Pango\Language::__construct() expects exactly 1 argument, 2 given
Pango\Language::__construct(): Argument #1 ($language) must be of type string, array given
