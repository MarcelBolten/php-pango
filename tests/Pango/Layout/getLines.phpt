--TEST--
Pango\Layout::getLines()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);

$pangoContext = new Pango\Context($fontMap);
var_dump($pangoContext);

$layout = new Pango\Layout($pangoContext);
var_dump($layout);

$lines = $layout->getLines();
var_dump($lines);

$layout->setText("AAA\nBB\nC");

$lines = $layout->getLines();
var_dump($lines);
var_dump($lines[0]->getLength());

// $layout->setText("change\ntext");

// this should fail if the lines are not re-fetched
// var_dump($lines[0]->getLength());

// $new_lines = $layout->getLines();
// var_dump($new_lines);
// var_dump($new_lines[0]->getLength());

try {
    $layout->getLines(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
array(1) {
  [0]=>
  object(Pango\LayoutLine)#%d (0) {
  }
}
array(3) {
  [0]=>
  object(Pango\LayoutLine)#%d (0) {
  }
  [1]=>
  object(Pango\LayoutLine)#%d (0) {
  }
  [2]=>
  object(Pango\LayoutLine)#%d (0) {
  }
}
int(3)
Pango\Layout::getLines() expects exactly 0 arguments, 1 given
