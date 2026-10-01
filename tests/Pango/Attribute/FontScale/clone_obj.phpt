--TEST--
Pango\Attribute\FontScale clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\FontScale;

$fontScale = new FontScale(Pango\FontScale::SmallCaps);
var_dump($fontScale->value);

$copy = clone $fontScale;
$copy->value = Pango\FontScale::Superscript;

var_dump($copy->value);
?>
--EXPECT--
enum(Pango\FontScale::SmallCaps)
enum(Pango\FontScale::Superscript)
