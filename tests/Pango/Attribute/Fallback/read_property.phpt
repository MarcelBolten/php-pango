--TEST--
Pango\Attribute\Fallback read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Fallback;

$fallback = new Fallback(true);

var_dump($fallback->value);
var_dump($fallback->startIndex);
var_dump($fallback->endIndex);
?>
--EXPECT--
bool(true)
int(0)
int(4294967295)
