--TEST--
Pango\Attribute\LanguageAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\LanguageAttribute;
use Pango\Language;

$attrLanguage = new LanguageAttribute(new Language("en"));

var_dump($attrLanguage->value->__toString());
var_dump($attrLanguage->startIndex);
var_dump($attrLanguage->endIndex);
?>
--EXPECTF--
string(2) "en"
int(0)
int(4294967295)
