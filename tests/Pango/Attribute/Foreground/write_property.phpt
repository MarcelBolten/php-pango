--TEST--
Pango\Attribute\Foreground object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Foreground;

$foreground = new Foreground(new Pango\Color(1024, 2048, 4096));
$foreground->color = new Pango\Color(512, 1024, 2048);
$foreground->startIndex = 13;
$foreground->endIndex = 42;

var_dump($foreground->color->red);
var_dump($foreground->startIndex);
var_dump($foreground->endIndex);

try {
    $foreground->color = 1;
}
catch (Throwable $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
int(512)
int(13)
int(42)
Cannot assign int to property Pango\Attribute\Foreground::$color of type Pango\Color
