--TEST--
Pango\LogAttrList::get()
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
var_dump($defaultBreakList->get(0));

try {
    $defaultBreakList->get(-1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $defaultBreakList->get(190);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $defaultBreakList->get();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $defaultBreakList->get(0, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $defaultBreakList->get(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\LogAttr)#%d (15) {
  ["lineBreak"]=>
  bool(false)
  ["mandatoryBreak"]=>
  bool(false)
  ["charBreak"]=>
  bool(true)
  ["white"]=>
  bool(false)
  ["cursorPosition"]=>
  bool(true)
  ["wordStart"]=>
  bool(true)
  ["wordEnd"]=>
  bool(false)
  ["sentenceBoundary"]=>
  bool(true)
  ["sentenceStart"]=>
  bool(true)
  ["sentenceEnd"]=>
  bool(false)
  ["backspaceDeletesCharacter"]=>
  bool(true)
  ["expandableSpace"]=>
  bool(false)
  ["wordBoundary"]=>
  bool(true)
  ["breakInsertsHyphen"]=>
  bool(false)
  ["breakRemovesPreceding"]=>
  bool(false)
}
Pango\LogAttrList::get(): Argument #1 ($byteIndex) must be between 0 and 189
Pango\LogAttrList::get(): Argument #1 ($byteIndex) must be between 0 and 189
Pango\LogAttrList::get() expects exactly 1 argument, 0 given
Pango\LogAttrList::get() expects exactly 1 argument, 2 given
Pango\LogAttrList::get(): Argument #1 ($byteIndex) must be of type int, array given
