--TEST--
Pango\Attribute\Language object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Language as AttrLanguage;
use Pango\Language;

$attrLanguage = new AttrLanguage(new Language("en"));
$attrLanguage->value = new Language("ja");
$attrLanguage->startIndex = 13;
$attrLanguage->endIndex = 42;

var_dump($attrLanguage->value->__toString());
var_dump($attrLanguage->startIndex);
var_dump($attrLanguage->endIndex);

try {
    $attrLanguage->value = 1;
}
catch (Throwable $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
string(2) "ja"
int(13)
int(42)
Cannot assign int to property Pango\Attribute\Language::$value of type Pango\Language
