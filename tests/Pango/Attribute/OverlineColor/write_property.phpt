--TEST--
Pango\Attribute\OverlineColor object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\OverlineColor;

$overlineColor = new OverlineColor(new Pango\Color(1024, 2048, 4096));
$overlineColor->color = new Pango\Color(512, 1024, 2048);
$overlineColor->startIndex = 13;
$overlineColor->endIndex = 42;

var_dump($overlineColor->color->red);
var_dump($overlineColor->startIndex);
var_dump($overlineColor->endIndex);

try {
    $overlineColor->color = 1;
}
catch (Throwable $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
int(512)
int(13)
int(42)
Cannot assign int to property Pango\Attribute\OverlineColor::$color of type Pango\Color
