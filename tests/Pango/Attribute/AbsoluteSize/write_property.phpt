--TEST--
Pango\Attribute\AbsoluteSize object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AbsoluteSize;

$absoluteSize = new AbsoluteSize(5);
$absoluteSize->value = 10;
$absoluteSize->startIndex = 13;
$absoluteSize->endIndex = 42;

var_dump($absoluteSize->value);
var_dump($absoluteSize->startIndex);
var_dump($absoluteSize->endIndex);
?>
--EXPECT--
int(10)
int(13)
int(42)
