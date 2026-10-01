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
  object(Pango\Analysis)#%d (7) {
    ["font"]=>
    object(Pango\Font)#6 (1) {
      ["string-representation"]=>
      string(15) "DejaVu Serif 12"
    }
    ["level"]=>
    int(0)
    ["gravity"]=>
    enum(Pango\Gravity::South)
    ["flags"]=>
    int(128)
    ["script"]=>
    enum(Pango\Script::Greek)
    ["language"]=>
    object(Pango\Language)#%d (1) {
      ["string-representation"]=>
      string(1) "c"
    }
    ["extraAttrs"]=>
    array(0) {
    }
  }
}
