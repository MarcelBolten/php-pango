--TEST--
Pango\LogAttrList::count()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\LogAttrList;

$text = <<<EOT
Hello, Παν語!

This is a test of the Pango\LogAttrList class constructor.
It needs a bit of text to analyze, so here is some more text to make sure we have enough characters to analyze.
EOT;

$defaultBreakList = LogAttrList::defaultBreak($text);
var_dump($defaultBreakList->count());
var_dump(count($defaultBreakList));

try {
    $defaultBreakList->count(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
int(%d)
int(%d)
Pango\LogAttrList::count() expects exactly 0 arguments, 1 given
