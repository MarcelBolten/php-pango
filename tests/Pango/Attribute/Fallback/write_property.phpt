--TEST--
Pango\Attribute\Fallback object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Fallback;

$fallback = new Fallback(true);
$fallback->value = false;
$fallback->startIndex = 13;
$fallback->endIndex = 42;

var_dump($fallback->value);
var_dump($fallback->startIndex);
var_dump($fallback->endIndex);
?>
--EXPECT--
bool(false)
int(13)
int(42)
