--TEST--
Pango\LogAttrList::tailorBreak()
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

$defaultBreakList = LogAttrList::defaultBreak($text);
var_dump($defaultBreakList);
var_dump($defaultBreakList->tailorBreak());

try {
    $defaultBreakList->tailorBreak(NULL, -2);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $defaultBreakList->tailorBreak(NULL, PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $defaultBreakList->tailorBreak(NULL, -1, 2);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $defaultBreakList->tailorBreak(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $defaultBreakList->tailorBreak(NULL, array());
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
object(Pango\LogAttrList)#%d (1) {
  ["text"]=>
  string(189) "Hello, Παν語!

This is a test of the Pango\LogAttrList class constructor.
It needs a bit of text to analyze, so here is some more text to make sure we have enough characters to analyze."
}
Pango\LogAttrList::tailorBreak(): Argument #2 ($byteOffset) must be between -1 and 2147483647
Pango\LogAttrList::tailorBreak(): Argument #2 ($byteOffset) must be between -1 and 2147483647
Pango\LogAttrList::tailorBreak() expects at most 2 arguments, 3 given
Pango\LogAttrList::tailorBreak(): Argument #1 ($analysis) must be of type ?Pango\Analysis, array given
Pango\LogAttrList::tailorBreak(): Argument #2 ($byteOffset) must be of type int, array given
