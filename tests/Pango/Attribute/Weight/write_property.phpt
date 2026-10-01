--TEST--
Pango\Attribute\Weight object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Weight;

$weight = new Weight(Pango\Weight::Bold);
$weight->value = Pango\Weight::Medium;
$weight->startIndex = 13;
$weight->endIndex = 42;

var_dump($weight->value);
var_dump($weight->startIndex);
var_dump($weight->endIndex);

try {
    $weight->value = 600;
}
catch (Throwable $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
enum(Pango\Weight::Medium)
int(13)
int(42)
Cannot assign int to property Pango\Attribute\Weight::$value of type Pango\Weight
