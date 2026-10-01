--TEST--
Pango\ParagraphBoundary::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\ParagraphBoundary;

var_dump(new ParagraphBoundary(10, 12));

try {
    new ParagraphBoundary();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ParagraphBoundary(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ParagraphBoundary(1, 2 ,3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ParagraphBoundary(array(), 2);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ParagraphBoundary(1, array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\ParagraphBoundary)#%d (2) {
  ["delimiterByteIndex"]=>
  int(10)
  ["nextStart"]=>
  int(12)
}
Pango\ParagraphBoundary::__construct() expects exactly 2 arguments, 0 given
Pango\ParagraphBoundary::__construct() expects exactly 2 arguments, 1 given
Pango\ParagraphBoundary::__construct() expects exactly 2 arguments, 3 given
Pango\ParagraphBoundary::__construct(): Argument #1 ($delimiterByteIndex) must be of type int, array given
Pango\ParagraphBoundary::__construct(): Argument #2 ($nextStart) must be of type int, array given
