--TEST--
Pango\Language::getScripts()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Language;

$language = new Language("en");
var_dump($language->getScripts());

$language = new Language("ja");
var_dump($language->getScripts());

try {
    $language->getScripts("test");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
array(1) {
  [0]=>
  enum(Pango\Script::Latin)
}
array(3) {
  [0]=>
  enum(Pango\Script::Han)
  [1]=>
  enum(Pango\Script::Katakana)
  [2]=>
  enum(Pango\Script::Hiragana)
}
Pango\Language::getScripts() expects exactly 0 arguments, 1 given
