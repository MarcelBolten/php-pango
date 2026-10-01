--TEST--
Pango\is_zero_width()
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
?>
--FILE--
<?php
use function Pango\is_zero_width;

var_dump(is_zero_width('a'));
var_dump(is_zero_width(''));
var_dump(is_zero_width("\u{200B}")); // ZERO WIDTH SPACE

try {
    is_zero_width("a\0");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    is_zero_width("__");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    is_zero_width();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    is_zero_width("a", "b");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    is_zero_width(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
bool(false)
bool(false)
bool(true)
Pango\is_zero_width(): Argument #1 ($char) must not contain NUL bytes
Pango\is_zero_width(): Argument #1 ($char) must be a single UTF-8 character
Pango\is_zero_width() expects exactly 1 argument, 0 given
Pango\is_zero_width() expects exactly 1 argument, 2 given
Pango\is_zero_width(): Argument #1 ($char) must be of type string, array given
