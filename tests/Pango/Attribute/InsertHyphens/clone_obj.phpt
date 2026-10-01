--TEST--
Pango\Attribute\InsertHyphens clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\InsertHyphens;

$insertHyphens = new InsertHyphens(true);
var_dump($insertHyphens->value);

$copy = clone $insertHyphens;
$copy->value = false;

var_dump($copy->value);
?>
--EXPECT--
bool(true)
bool(false)
