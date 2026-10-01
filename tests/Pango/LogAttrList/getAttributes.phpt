--TEST--
Pango\LogAttrList::getAttributes()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\LogAttrList;

$defaultBreakList = LogAttrList::defaultBreak("Hello, Παν語!");
$attrs = $defaultBreakList->getAttributes();
var_dump(count($attrs));
var_dump($attrs[0]);
var_dump($attrs[17]);

try {
    $defaultBreakList->getAttributes(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
int(18)
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
object(Pango\LogAttr)#%d (15) {
  ["lineBreak"]=>
  bool(false)
  ["mandatoryBreak"]=>
  bool(false)
  ["charBreak"]=>
  bool(false)
  ["white"]=>
  bool(false)
  ["cursorPosition"]=>
  bool(false)
  ["wordStart"]=>
  bool(false)
  ["wordEnd"]=>
  bool(false)
  ["sentenceBoundary"]=>
  bool(false)
  ["sentenceStart"]=>
  bool(false)
  ["sentenceEnd"]=>
  bool(false)
  ["backspaceDeletesCharacter"]=>
  bool(false)
  ["expandableSpace"]=>
  bool(false)
  ["wordBoundary"]=>
  bool(false)
  ["breakInsertsHyphen"]=>
  bool(false)
  ["breakRemovesPreceding"]=>
  bool(false)
}
Pango\LogAttrList::getAttributes() expects exactly 0 arguments, 1 given
