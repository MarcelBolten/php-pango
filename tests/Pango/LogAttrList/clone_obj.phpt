--TEST--
Pango\LogAttrList clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\LogAttrList;
use Pango\Language;

$text = <<<EOT
Hello, Παν語!

This is a test of the Pango\LogAttrList class constructor.
It needs a bit of text to analyze, so here is some more text to make sure we have enough characters to analyze.
EOT;

$logAttr_list = new LogAttrList($text);
var_dump($logAttr_list);
$clone = clone $logAttr_list;
var_dump($clone);
var_dump($clone !== $logAttr_list);
?>
--EXPECTF--
object(Pango\LogAttrList)#1 (1) {
  ["text"]=>
  string(%d) "Hello, Παν語!

This is a test of the Pango\LogAttrList class constructor.
It needs a bit of text to analyze, so here is some more text to make sure we have enough characters to analyze."
}
object(Pango\LogAttrList)#2 (1) {
  ["text"]=>
  string(%d) "Hello, Παν語!

This is a test of the Pango\LogAttrList class constructor.
It needs a bit of text to analyze, so here is some more text to make sure we have enough characters to analyze."
}
bool(true)
