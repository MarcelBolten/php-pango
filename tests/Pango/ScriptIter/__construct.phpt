--TEST--
Pango\ScriptIter::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\ScriptIter;

$scriptIter = new ScriptIter("Text");
var_dump($scriptIter);

try {
    new ScriptIter("Text\0");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ScriptIter();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ScriptIter("Text", 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ScriptIter(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\ScriptIter)#%d (0) {
}
Pango\ScriptIter::__construct(): Argument #1 ($text) must not contain NUL bytes
Pango\ScriptIter::__construct() expects exactly 1 argument, 0 given
Pango\ScriptIter::__construct() expects exactly 1 argument, 2 given
Pango\ScriptIter::__construct(): Argument #1 ($text) must be of type string, array given
