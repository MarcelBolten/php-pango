--TEST--
Pango\Attribute\FontScale read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\FontScale;

$fontScale = new FontScale(Pango\FontScale::SmallCaps);

var_dump($fontScale->value);
var_dump($fontScale->startIndex);
var_dump($fontScale->endIndex);
?>
--EXPECT--
enum(Pango\FontScale::SmallCaps)
int(0)
int(4294967295)
