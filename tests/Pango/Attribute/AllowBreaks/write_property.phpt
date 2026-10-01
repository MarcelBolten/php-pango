--TEST--
Pango\Attribute\AllowBreaks object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AllowBreaks;

$allowBreaks = new AllowBreaks(true);
$allowBreaks->value = false;
$allowBreaks->startIndex = 13;
$allowBreaks->endIndex = 42;

var_dump($allowBreaks->value);
var_dump($allowBreaks->startIndex);
var_dump($allowBreaks->endIndex);
?>
--EXPECT--
bool(false)
int(13)
int(42)
