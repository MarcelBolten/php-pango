--TEST--
Pango\Language::getDefault()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Language;

setlocale(LC_ALL, "en_US.UTF-8");

$language = Language::getDefault();
var_dump($language);

try {
    $language = Language::getDefault("en");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Language)#1 (1) {
  ["string-representation"]=>
  string(5) "en-us"
}
Pango\Language::getDefault() expects exactly 0 arguments, 1 given
