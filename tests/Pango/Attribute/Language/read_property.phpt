--TEST--
Pango\Attribute\Language read_property handler
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
var_dump($attrLanguage->startIndex);
var_dump($attrLanguage->endIndex);
?>
--EXPECTF--
string(2) "en"
int(0)
int(4294967295)
