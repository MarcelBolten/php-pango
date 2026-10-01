--TEST--
Pango\Attribute\TextTransform clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\TextTransform;

$textTransform = new TextTransform(Pango\TextTransform::Lowercase);
var_dump($textTransform->value);

$copy = clone $textTransform;
$copy->value = Pango\TextTransform::Uppercase;

var_dump($copy->value);
?>
--EXPECT--
enum(Pango\TextTransform::Lowercase)
enum(Pango\TextTransform::Uppercase)
