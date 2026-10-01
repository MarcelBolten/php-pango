--TEST--
Pango\Attribute\Rise read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Rise;

$rise = new Rise(5);

var_dump($rise->value);
var_dump($rise->startIndex);
var_dump($rise->endIndex);
?>
--EXPECT--
int(5)
int(0)
int(4294967295)
