--TEST--
Pango\Attribute\Underline object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Underline;

$underline = new Underline(Pango\Underline::Double);
$underline->value = Pango\Underline::Error;
$underline->startIndex = 13;
$underline->endIndex = 42;

var_dump($underline->value);
var_dump($underline->startIndex);
var_dump($underline->endIndex);

try {
    $underline->value = 0;
}
catch (Throwable $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
enum(Pango\Underline::Error)
int(13)
int(42)
Cannot assign int to property Pango\Attribute\Underline::$value of type Pango\Underline
