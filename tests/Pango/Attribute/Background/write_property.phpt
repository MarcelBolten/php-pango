--TEST--
Pango\Attribute\Background object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Background;

$background = new Background(new Pango\Color(1024, 2048, 4096));
$background->color = new Pango\Color(512, 1024, 2048);
$background->startIndex = 13;
$background->endIndex = 42;

var_dump($background->color->red);
var_dump($background->startIndex);
var_dump($background->endIndex);

try {
    $background->color = 1;
}
catch (Throwable $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
int(512)
int(13)
int(42)
Cannot assign int to property Pango\Attribute\Background::$color of type Pango\Color
