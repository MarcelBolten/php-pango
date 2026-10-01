--TEST--
Pango\Attribute\Show read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Show;

$show = new Show(Show::NONE);

var_dump($show->value);
var_dump($show->startIndex);
var_dump($show->endIndex);
?>
--EXPECT--
int(0)
int(0)
int(4294967295)
