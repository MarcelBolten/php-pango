--TEST--
Pango\Attribute\UnderlineColor object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\UnderlineColor;

$underlineColor = new UnderlineColor(new Pango\Color(1024, 2048, 4096));
$underlineColor->color = new Pango\Color(512, 1024, 2048);
$underlineColor->startIndex = 13;
$underlineColor->endIndex = 42;

var_dump($underlineColor->color->red);
var_dump($underlineColor->startIndex);
var_dump($underlineColor->endIndex);

try {
    $underlineColor->color = 1;
}
catch (Throwable $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
int(512)
int(13)
int(42)
Cannot assign int to property Pango\Attribute\UnderlineColor::$color of type Pango\Color
