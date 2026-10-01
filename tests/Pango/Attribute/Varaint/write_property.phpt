--TEST--
Pango\Attribute\Variant object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Variant;

$variant = new Variant(Pango\Variant::SmallCaps);
$variant->value = Pango\Variant::TitleCaps;
$variant->startIndex = 13;
$variant->endIndex = 42;

var_dump($variant->value);
var_dump($variant->startIndex);
var_dump($variant->endIndex);

try {
    $variant->value = 1;
}
catch (Throwable $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
enum(Pango\Variant::TitleCaps)
int(13)
int(42)
Cannot assign int to property Pango\Attribute\Variant::$value of type Pango\Variant
