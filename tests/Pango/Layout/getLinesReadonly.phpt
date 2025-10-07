--TEST--
Pango\Layout::getLinesReadonly()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$layout = new Pango\Layout($cairoContext);
var_dump($layout);

$lines = $layout->getLinesReadonly();
var_dump($lines);

$layout->setText("AAA\nBB\nC");

$lines = $layout->getLinesReadonly();
var_dump($lines);
var_dump($lines[0]->getLength());

$layout->setText("change\ntext");

// this should fail if the lines are not re-fetched
// var_dump($lines[0]->getLength());

// $new_lines = $layout->getLinesReadonly();
// var_dump($new_lines);
// var_dump($new_lines[0]->getLength());

try {
    $layout->getLinesReadonly(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
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
Pango\Layout::getLinesReadonly() expects exactly 0 arguments, 1 given
