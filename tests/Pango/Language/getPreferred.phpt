--TEST--
Pango\Language::getPreferred()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Language;

putenv("PANGO_LANGUAGE=en");

$language = Language::getPreferred();
var_dump($language);

try {
    $language = Language::getPreferred("en");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
array(1) {
  [0]=>
  object(Pango\Language)#1 (1) {
    ["string-representation"]=>
    string(2) "en"
  }
}
Pango\Language::getPreferred() expects exactly 0 arguments, 1 given
