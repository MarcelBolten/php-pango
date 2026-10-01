--TEST--
Pango\find_paragraph_boundary()
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
?>
--FILE--
<?php
use function Pango\find_paragraph_boundary;

var_dump(find_paragraph_boundary("Hello, Παν語!"));
var_dump(find_paragraph_boundary("Hello,\nΠαν語!"));

try {
    find_paragraph_boundary("Hello,\0Παν語!");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    find_paragraph_boundary();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    find_paragraph_boundary("a", "b");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    find_paragraph_boundary(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\ParagraphBoundary)#%d (2) {
  ["delimiterByteIndex"]=>
  int(17)
  ["nextStart"]=>
  int(17)
}
object(Pango\ParagraphBoundary)#%d (2) {
  ["delimiterByteIndex"]=>
  int(6)
  ["nextStart"]=>
  int(7)
}
Pango\find_paragraph_boundary(): Argument #1 ($text) must not contain NUL bytes
Pango\find_paragraph_boundary() expects exactly 1 argument, 0 given
Pango\find_paragraph_boundary() expects exactly 1 argument, 2 given
Pango\find_paragraph_boundary(): Argument #1 ($text) must be of type string, array given
