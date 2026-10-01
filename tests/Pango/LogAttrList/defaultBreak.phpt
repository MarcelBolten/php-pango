--TEST--
Pango\LogAttrList::defaultBreak()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\LogAttrList;

$text = <<<EOT
Hello, Παν語!

This is a test of the Pango\LogAttrList class constructor.
It needs a bit of text to analyze, so here is some more text to make sure we have enough characters to analyze.
EOT;

var_dump(LogAttrList::defaultBreak($text));

try {
    LogAttrList::defaultBreak($text . "\0");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    LogAttrList::defaultBreak();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    LogAttrList::defaultBreak($text, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    LogAttrList::defaultBreak(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\LogAttrList)#%d (1) {
  ["text"]=>
  string(189) "Hello, Παν語!

This is a test of the Pango\LogAttrList class constructor.
It needs a bit of text to analyze, so here is some more text to make sure we have enough characters to analyze."
}
Pango\LogAttrList::defaultBreak(): Argument #1 ($text) must not contain NUL bytes
Pango\LogAttrList::defaultBreak() expects exactly 1 argument, 0 given
Pango\LogAttrList::defaultBreak() expects exactly 1 argument, 2 given
Pango\LogAttrList::defaultBreak(): Argument #1 ($text) must be of type string, array given
