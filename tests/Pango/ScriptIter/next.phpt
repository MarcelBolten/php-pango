--TEST--
Pango\ScriptIter::next()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\ScriptIter;

$scriptIter = new ScriptIter("English 中文");
var_dump($scriptIter);
var_dump($scriptIter->next());

$scriptIter2 = new ScriptIter("English only.");
var_dump($scriptIter2->next());

try {
    $scriptIter->next(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\ScriptIter)#%d (0) {
}
bool(true)
bool(false)
Pango\ScriptIter::next() expects exactly 0 arguments, 1 given
