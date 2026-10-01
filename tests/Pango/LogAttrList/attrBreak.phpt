--TEST--
Pango\LogAttrList::attrBreak()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\LogAttrList;
use Pango\Attribute\AttributeList;

$text = <<<EOT
Hello, Παν語!

This is a test of the Pango\LogAttrList class constructor.
It needs a bit of text to analyze, so here is some more text to make sure we have enough characters to analyze.
EOT;

$tailorBreakList = LogAttrList::defaultBreak($text)->tailorBreak();
$attrList = new AttributeList();
var_dump($tailorBreakList->attrBreak($attrList));

try {
    $tailorBreakList->attrBreak($attrList, -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $tailorBreakList->attrBreak($attrList, PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $tailorBreakList->attrBreak();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $tailorBreakList->attrBreak($attrList, 0, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $tailorBreakList->attrBreak(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $tailorBreakList->attrBreak($attrList, array());
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
Pango\LogAttrList::attrBreak(): Argument #2 ($byteOffset) must be between 0 and 2147483647
Pango\LogAttrList::attrBreak(): Argument #2 ($byteOffset) must be between 0 and 2147483647
Pango\LogAttrList::attrBreak() expects at least 1 argument, 0 given
Pango\LogAttrList::attrBreak() expects at most 2 arguments, 3 given
Pango\LogAttrList::attrBreak(): Argument #1 ($attrList) must be of type Pango\Attribute\AttributeList, array given
Pango\LogAttrList::attrBreak(): Argument #2 ($byteOffset) must be of type int, array given
