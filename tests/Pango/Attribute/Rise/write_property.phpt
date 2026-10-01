--TEST--
Pango\Attribute\Rise object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Rise;

$rise = new Rise(5);
$rise->value = 10;
$rise->startIndex = 13;
$rise->endIndex = 42;

var_dump($rise->value);
var_dump($rise->startIndex);
var_dump($rise->endIndex);
?>
--EXPECT--
int(10)
int(13)
int(42)
