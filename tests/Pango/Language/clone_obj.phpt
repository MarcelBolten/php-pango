--TEST--
Pango\Language clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$language = new Pango\Language("en");
var_dump($language);
var_dump(clone $language);
?>
--EXPECT--
object(Pango\Language)#1 (1) {
  ["string-representation"]=>
  string(2) "en"
}
object(Pango\Language)#2 (1) {
  ["string-representation"]=>
  string(2) "en"
}
