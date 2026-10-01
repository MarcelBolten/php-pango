--TEST--
Pango\Attribute\Overline object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Overline;

$overline = new Overline(Pango\Overline::None);
$overline->value = Pango\Overline::Single;
$overline->startIndex = 13;
$overline->endIndex = 42;

var_dump($overline->value);
var_dump($overline->startIndex);
var_dump($overline->endIndex);

try {
    $overline->value = 0;
}
catch (Throwable $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
enum(Pango\Overline::Single)
int(13)
int(42)
Cannot assign int to property Pango\Attribute\Overline::$value of type Pango\Overline
