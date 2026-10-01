--TEST--
Pango\Language::getSampleString()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Language;

$language = new Language("en-ca");
var_dump($language->getSampleString());

$language = new Language("ja");
var_dump($language->getSampleString());

$language = new Language("ar");
var_dump($language->getSampleString());

try {
    $language->getSampleString("test");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
string(59) "The wizard quickly jinxed the gnomes before they vaporized."
string(69) "いろはにほへと ちりぬるを 色は匂へど 散りぬるを"
string(119) "نص حكيم له سر قاطع وذو شأن عظيم مكتوب على ثوب أخضر ومغلف بجلد أزرق."
Pango\Language::getSampleString() expects exactly 0 arguments, 1 given
