--TEST--
Pango\Attribute\InsertHyphens object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\InsertHyphens;

$insertHyphens = new InsertHyphens(true);
$insertHyphens->value = false;
$insertHyphens->startIndex = 13;
$insertHyphens->endIndex = 42;

var_dump($insertHyphens->value);
var_dump($insertHyphens->startIndex);
var_dump($insertHyphens->endIndex);
?>
--EXPECT--
bool(false)
int(13)
int(42)
