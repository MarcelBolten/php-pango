--TEST--
Pango\Attribute\StrikethroughColor object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\StrikethroughColor;

$strikethroughColor = new StrikethroughColor(new Pango\Color(1024, 2048, 4096));
$strikethroughColor->color = new Pango\Color(512, 1024, 2048);
$strikethroughColor->startIndex = 13;
$strikethroughColor->endIndex = 42;

var_dump($strikethroughColor->color->red);
var_dump($strikethroughColor->startIndex);
var_dump($strikethroughColor->endIndex);

try {
    $strikethroughColor->color = 1;
}
catch (Throwable $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
int(512)
int(13)
int(42)
Cannot assign int to property Pango\Attribute\StrikethroughColor::$color of type Pango\Color
