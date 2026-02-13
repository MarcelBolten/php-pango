--TEST--
Pango\Item read property handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$layout = new PangoCairo\Layout($cairoContext);
var_dump($layout);

$layout->setText("Hello, Παν語!");
foreach ($layout->getLinesReadonly() as $line) {
    $item = $line->getRuns()[1]->item;
    var_dump($item->offset);
    var_dump($item->length);
    var_dump($item->numChars);
    var_dump($item->analysis);
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
int(7)
int(6)
int(3)
array(7) {
  ["bidiLevel"]=>
  int(0)
  ["gravity"]=>
  enum(Pango\Gravity::South)
  ["centeredBaseline"]=>
  bool(false)
  ["isEllipsis"]=>
  bool(false)
  ["needsHyphen"]=>
  bool(false)
  ["script"]=>
  string(4) "Grek"
  ["language"]=>
  string(%d) "%s"
}
