--TEST--
Pango\Attribute\Family object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Family;

$family = new Family("Arial");
$family->value = "Times New Roman";
$family->startIndex = 13;
$family->endIndex = 42;

var_dump($family->value);
var_dump($family->startIndex);
var_dump($family->endIndex);
?>
--EXPECT--
string(15) "Times New Roman"
int(13)
int(42)
