--TEST--
Pango\Item get_properties handler
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
var_dump($layout->getLine(0)->getRuns()[1]->item);
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
object(Pango\Item)#%d (4) {
  ["offset"]=>
  int(7)
  ["length"]=>
  int(6)
  ["numChars"]=>
  int(3)
  ["analysis"]=>
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
    string(1) "c"
  }
}
