--TEST--
Pango\log2vis_get_embedding_levels()
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Direction;
use function Pango\log2vis_get_embedding_levels;

$text = "שלום, Παν語!";
var_dump(log2vis_get_embedding_levels($text, Direction::WeakRTL));

try {
    log2vis_get_embedding_levels($text . "\0", Direction::WeakRTL);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    log2vis_get_embedding_levels();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    log2vis_get_embedding_levels($text, Direction::WeakRTL, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    log2vis_get_embedding_levels(array(), Direction::WeakRTL);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    log2vis_get_embedding_levels($text, array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
array(11) {
  [0]=>
  int(1)
  [1]=>
  int(1)
  [2]=>
  int(1)
  [3]=>
  int(1)
  [4]=>
  int(1)
  [5]=>
  int(1)
  [6]=>
  int(2)
  [7]=>
  int(2)
  [8]=>
  int(2)
  [9]=>
  int(2)
  [10]=>
  int(1)
}
Pango\log2vis_get_embedding_levels(): Argument #1 ($text) must not contain NUL bytes
Pango\log2vis_get_embedding_levels() expects exactly 2 arguments, 0 given
Pango\log2vis_get_embedding_levels() expects exactly 2 arguments, 3 given
Pango\log2vis_get_embedding_levels(): Argument #1 ($text) must be of type string, array given
Pango\log2vis_get_embedding_levels(): Argument #2 ($baseDirection) must be of type Pango\Direction, array given
