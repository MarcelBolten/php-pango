--TEST--
Pango\LogAttr read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$logattr = new Pango\LogAttr();

var_dump($logattr->lineBreak);
var_dump($logattr->mandatoryBreak);
var_dump($logattr->charBreak);
var_dump($logattr->white);
var_dump($logattr->cursorPosition);
var_dump($logattr->wordStart);
var_dump($logattr->wordEnd);
var_dump($logattr->sentenceStart);
var_dump($logattr->sentenceEnd);
var_dump($logattr->backspaceDeletesCharacter);
var_dump($logattr->expandableSpace);
var_dump($logattr->wordBoundary);
var_dump($logattr->breakInsertsHyphen);
var_dump($logattr->breakRemovesPreceding);
?>
--EXPECT--
bool(false)
bool(false)
bool(false)
bool(false)
bool(false)
bool(false)
bool(false)
bool(false)
bool(false)
bool(false)
bool(false)
bool(false)
bool(false)
bool(false)
