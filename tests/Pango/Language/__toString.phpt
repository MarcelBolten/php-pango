--TEST--
Pango\Language::__toString
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Language;

$language = new Language("en");
var_dump($language->__toString());
echo $language, "\n";

$language_tags = [
    "*",
    "en-ca",
    "not-a-valid-language-tag",
    "",
];
foreach ($language_tags as $tag) {
    $language = new Language($tag);
    var_dump($language->__toString());
}
?>
--EXPECTF--
string(2) "en"
en
string(0) ""
string(5) "en-ca"
string(24) "not-a-valid-language-tag"
string(0) ""