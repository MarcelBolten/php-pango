--TEST--
Pango\Attribute\FallbackAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\FallbackAttribute;

$fallback = new FallbackAttribute(true);
var_dump($fallback->value);

$copy = clone $fallback;
var_dump($copy->value);
?>
--EXPECT--
bool(true)
bool(true)
