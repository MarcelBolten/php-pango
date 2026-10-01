--TEST--
Pango\Attribute\FontScale object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\FontScale;

$fontScale = new FontScale(Pango\FontScale::SmallCaps);
$fontScale->value = Pango\FontScale::Superscript;
$fontScale->startIndex = 13;
$fontScale->endIndex = 42;

var_dump($fontScale->value);
var_dump($fontScale->startIndex);
var_dump($fontScale->endIndex);

try {
    $fontScale->value = 1;
}
catch (Throwable $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
enum(Pango\FontScale::Superscript)
int(13)
int(42)
Cannot assign int to property Pango\Attribute\FontScale::$value of type Pango\FontScale
