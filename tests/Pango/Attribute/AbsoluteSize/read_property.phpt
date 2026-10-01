--TEST--
Pango\Attribute\AbsoluteSize read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AbsoluteSize;

$absoluteSize = new AbsoluteSize(5);

var_dump($absoluteSize->value);
var_dump($absoluteSize->startIndex);
var_dump($absoluteSize->endIndex);
?>
--EXPECT--
int(5)
int(0)
int(4294967295)
