--TEST--
Pango\LogAttr get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
$logattr = new Pango\LogAttr();
var_dump($logattr);
// The expected result has trailing whitespace
print_r($logattr);
?>
--EXPECTF--
object(Pango\LogAttr)#1 (15) {
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
Pango\LogAttr Object
(
    [lineBreak] => 
    [mandatoryBreak] => 
    [charBreak] => 
    [white] => 
    [cursorPosition] => 
    [wordStart] => 
    [wordEnd] => 
    [sentenceBoundary] => 
    [sentenceStart] => 
    [sentenceEnd] => 
    [backspaceDeletesCharacter] => 
    [expandableSpace] => 
    [wordBoundary] => 
    [breakInsertsHyphen] => 
    [breakRemovesPreceding] => 
)
