--TEST--
Pango\Language::matches()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Language;

$language = new Language("en-US");
var_dump($language->matches("en"));

$language = new Language("en-US");
var_dump($language->matches("de: fr, ja; es"));

try {
    $language->matches("en\0");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $language->matches();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $language->matches("en", "extra");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $language->matches(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
bool(true)
bool(false)
Pango\Language::matches(): Argument #1 ($languageRange) must not contain NUL bytes
Pango\Language::matches() expects exactly 1 argument, 0 given
Pango\Language::matches() expects exactly 1 argument, 2 given
Pango\Language::matches(): Argument #1 ($languageRange) must be of type string, array given
