--TEST--
Pango\TabStops::fromString()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\TabStops;

var_dump(TabStops::fromString("10240"));
var_dump(TabStops::fromString("100px"));
var_dump(TabStops::fromString("right:10240"));
var_dump(TabStops::fromString("decimal:10240:65"));

try {
    TabStops::fromString("decimal:10240:.\0");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    TabStops::fromString("decimal:10240:WRONG");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    TabStops::fromString();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    TabStops::fromString("100px", 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    TabStops::fromString(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\TabStops)#%d (0) {
}
object(Pango\TabStops)#%d (0) {
}
object(Pango\TabStops)#%d (0) {
}
object(Pango\TabStops)#%d (0) {
}
Pango\TabStops::fromString(): Argument #1 ($str) must not contain NUL bytes
Pango\TabStops::fromString(): Argument #1 ($str) must be a valid Pango tab array string, but "decimal:10240:WRONG" was given
Pango\TabStops::fromString() expects exactly 1 argument, 0 given
Pango\TabStops::fromString() expects exactly 1 argument, 2 given
Pango\TabStops::fromString(): Argument #1 ($str) must be of type string, array given
