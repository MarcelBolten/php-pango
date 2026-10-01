--TEST--
Pango\Attribute\Sentence read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Sentence;

$sentence = new Sentence();

var_dump($sentence->startIndex);
var_dump($sentence->endIndex);
?>
--EXPECT--
int(0)
int(4294967295)
