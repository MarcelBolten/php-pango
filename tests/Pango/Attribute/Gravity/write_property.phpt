--TEST--
Pango\Attribute\Gravity object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Gravity;

$gravity = new Gravity(Pango\Gravity::North);
$gravity->value = Pango\Gravity::South;
$gravity->startIndex = 13;
$gravity->endIndex = 42;

var_dump($gravity->value);
var_dump($gravity->startIndex);
var_dump($gravity->endIndex);

try {
    $gravity->value = 0;
}
catch (Throwable $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
enum(Pango\Gravity::South)
int(13)
int(42)
Cannot assign int to property Pango\Attribute\Gravity::$value of type Pango\Gravity
