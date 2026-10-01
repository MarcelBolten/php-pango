--TEST--
Pango\ScriptIter::getRange()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\ScriptIter;

$scriptIter = new ScriptIter("English 中文 العربية");
var_dump($scriptIter);
do {
    var_dump($scriptIter->getRange());
} while ($scriptIter->next());

try {
    $scriptIter->getRange(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\ScriptIter)#%d (0) {
}
object(Pango\ScriptIterRange)#%d (4) {
  ["text"]=>
  string(8) "English "
  ["byteStart"]=>
  int(0)
  ["byteEnd"]=>
  int(8)
  ["script"]=>
  enum(Pango\Script::Latin)
}
object(Pango\ScriptIterRange)#%d (4) {
  ["text"]=>
  string(7) "中文 "
  ["byteStart"]=>
  int(8)
  ["byteEnd"]=>
  int(15)
  ["script"]=>
  enum(Pango\Script::Han)
}
object(Pango\ScriptIterRange)#%d (4) {
  ["text"]=>
  string(14) "العربية"
  ["byteStart"]=>
  int(15)
  ["byteEnd"]=>
  int(29)
  ["script"]=>
  enum(Pango\Script::Arabic)
}
Pango\ScriptIter::getRange() expects exactly 0 arguments, 1 given
