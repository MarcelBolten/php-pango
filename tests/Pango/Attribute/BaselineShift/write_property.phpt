--TEST--
Pango\Attribute\BaselineShift object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\BaselineShift;

$baselineShift = new BaselineShift(Pango\BaselineShift::Superscript);
$baselineShift->value = Pango\BaselineShift::Subscript;
$baselineShift->startIndex = 13;
$baselineShift->endIndex = 42;

var_dump($baselineShift->value);
var_dump($baselineShift->startIndex);
var_dump($baselineShift->endIndex);

$baselineShift->value = 10240;
var_dump($baselineShift->value);

try {
    $baselineShift->value = array();
}
catch (Throwable $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
enum(Pango\BaselineShift::Subscript)
int(13)
int(42)
int(10240)
Cannot assign array to property Pango\Attribute\BaselineShift::$value of type Pango\BaselineShift|int
