--TEST--
Pango\LogAttrList::getIterator()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\LogAttrList;

$defaultBreakList = LogAttrList::defaultBreak("Hello, Παν語!");
foreach ($defaultBreakList as $logAttr) {
  var_dump($logAttr->wordStart);
}

try {
    $defaultBreakList->getIterator(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
bool(true)
bool(false)
bool(false)
bool(false)
bool(false)
bool(false)
bool(false)
bool(true)
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
Pango\LogAttrList::getIterator() expects exactly 0 arguments, 1 given
