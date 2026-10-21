--TEST--
Pango\Attribute\LanguageAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\LanguageAttribute as AttrLanguage;
use Pango\Language;

$attrLanguage = new AttrLanguage(new Language("en"));
var_dump($attrLanguage->value->__toString());

$copy = clone $attrLanguage;
var_dump($copy->value->__toString());
?>
--EXPECTF--
string(2) "en"
string(2) "en"
