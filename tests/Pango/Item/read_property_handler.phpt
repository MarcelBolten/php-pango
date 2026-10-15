--TEST--
Pango\Item read property handler
--EXTENSIONS--
pango
cairo
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$layout = new PangoCairo\Layout($cairoContext);
var_dump($layout);

$layout->setText("Hello, Παν語!");

$item = $layout->getLine(0)->getRuns()[1]->item;
var_dump($item->offset);
var_dump($item->length);
var_dump($item->numChars);
var_dump($item->analysis);
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
int(7)
int(6)
int(3)
object(Pango\Analysis)#%d (7) {
  ["font"]=>
  object(Pango\Font)#6 (1) {
    ["string-representation"]=>
    string(%d) "%s"
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
    string(%d) "%s"
  }
  ["extraAttrs"]=>
  array(0) {
  }
}
