--TEST--
Pango\Attribute\TextTransform object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\TextTransform;

$textTransform = new TextTransform(Pango\TextTransform::Lowercase);
$textTransform->value = Pango\TextTransform::Uppercase;
$textTransform->startIndex = 13;
$textTransform->endIndex = 42;

var_dump($textTransform->value);
var_dump($textTransform->startIndex);
var_dump($textTransform->endIndex);

try {
    $textTransform->value = 0;
}
catch (Throwable $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
enum(Pango\TextTransform::Uppercase)
int(13)
int(42)
Cannot assign int to property Pango\Attribute\TextTransform::$value of type Pango\TextTransform
