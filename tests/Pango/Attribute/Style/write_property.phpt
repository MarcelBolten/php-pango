--TEST--
Pango\Attribute\Style object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Style;

$style = new Style(Pango\Style::Italic);
$style->value = Pango\Style::Oblique;
$style->startIndex = 13;
$style->endIndex = 42;

var_dump($style->value);
var_dump($style->startIndex);
var_dump($style->endIndex);

try {
    $style->value = 1;
}
catch (Throwable $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
enum(Pango\Style::Oblique)
int(13)
int(42)
Cannot assign int to property Pango\Attribute\Style::$value of type Pango\Style
