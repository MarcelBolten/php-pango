--TEST--
Pango\Attribute\AllowBreaks clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AllowBreaks;

$allowBreaks = new AllowBreaks(true);
var_dump($allowBreaks->value);

$copy = clone $allowBreaks;
$copy->value = false;

var_dump($copy->value);
?>
--EXPECT--
bool(true)
bool(false)
