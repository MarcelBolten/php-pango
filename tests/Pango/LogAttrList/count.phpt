--TEST--
Pango\LogAttrList::count()
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
var_dump($defaultBreakList->count());
var_dump(count($defaultBreakList));

try {
    $defaultBreakList->count(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
int(190)
int(190)
Pango\LogAttrList::count() expects exactly 0 arguments, 1 given
