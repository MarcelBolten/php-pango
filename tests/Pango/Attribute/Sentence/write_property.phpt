--TEST--
Pango\Attribute\Sentence object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Sentence;

$sentence = new Sentence();
$sentence->startIndex = 13;
$sentence->endIndex = 42;

var_dump($sentence->startIndex);
var_dump($sentence->endIndex);
?>
--EXPECT--
int(13)
int(42)
