--TEST--
Pango\Attribute\Rise clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Rise;

$rise = new Rise(5);
var_dump($rise->value);

$copy = clone $rise;
var_dump($copy->value);
?>
--EXPECT--
int(5)
int(5)
