--TEST--
Pango\Attribute\AbsoluteSize clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AbsoluteSize;

$absoluteSize = new AbsoluteSize(5);
var_dump($absoluteSize->value);

$copy = clone $absoluteSize;
$copy->value = 9;

var_dump($copy->value);
?>
--EXPECT--
int(5)
int(9)
