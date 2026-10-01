--TEST--
Pango\Attribute\Language clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Language as AttrLanguage;
use Pango\Language;

$attrLanguage = new AttrLanguage(new Language("en"));
var_dump($attrLanguage->value->__toString());

$copy = clone $attrLanguage;
$copy->value = new Language("ja");

var_dump($copy->value->__toString());
?>
--EXPECTF--
string(2) "en"
string(2) "ja"
