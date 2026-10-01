--TEST--
Pango\Attribute\Show object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Show;

$show = new Show(Show::NONE);
$show->value = Show::LINE_BREAKS;
$show->startIndex = 13;
$show->endIndex = 42;

var_dump($show->value);
var_dump($show->startIndex);
var_dump($show->endIndex);
?>
--EXPECT--
int(2)
int(13)
int(42)
