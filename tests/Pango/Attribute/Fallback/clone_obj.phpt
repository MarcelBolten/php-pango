--TEST--
Pango\Attribute\Fallback clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\Fallback;

$fallback = new Fallback(true);
var_dump($fallback->value);

$copy = clone $fallback;
var_dump($copy->value);
?>
--EXPECT--
bool(true)
bool(true)
