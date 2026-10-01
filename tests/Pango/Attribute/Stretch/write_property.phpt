--TEST--
Pango\Attribute\Stretch object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Stretch;

$stretch = new Stretch(Pango\Stretch::Expanded);
$stretch->value = Pango\Stretch::Condensed;
$stretch->startIndex = 13;
$stretch->endIndex = 42;

var_dump($stretch->value);
var_dump($stretch->startIndex);
var_dump($stretch->endIndex);

try {
    $stretch->value = 0;
}
catch (Throwable $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
enum(Pango\Stretch::Condensed)
int(13)
int(42)
Cannot assign int to property Pango\Attribute\Stretch::$value of type Pango\Stretch
