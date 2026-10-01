--TEST--
Pango\Attribute\Strikethrough clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Strikethrough;

$strikethrough = new Strikethrough(true);
var_dump($strikethrough->value);

$copy = clone $strikethrough;
$copy->value = false;

var_dump($copy->value);
?>
--EXPECT--
bool(true)
bool(false)
