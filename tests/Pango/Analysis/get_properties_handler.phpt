--TEST--
Pango\Analysis get_properties handler
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
$layout->setAttributes(new Pango\Attribute\AttributeList("0 20 foreground red, 0 20 language en, 0 20 font-desc \"Sans 12\""));
$analysis_object = $layout->getLine(0)->getRuns()[1]->item->analysis;
var_dump($analysis_object);
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
object(Pango\Analysis)#%d (7) {
  ["font"]=>
  object(Pango\Font)#%d (1) {
    ["string-representation"]=>
    string(14) "DejaVu Sans 12"
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
    string(2) "en"
  }
  ["extraAttrs"]=>
  array(1) {
    [0]=>
    object(Pango\Attribute\Foreground)#%d (3) {
      ["startIndex"]=>
      int(0)
      ["endIndex"]=>
      int(20)
      ["color"]=>
      object(Pango\Color)#%d (3) {
        ["red"]=>
        int(65535)
        ["green"]=>
        int(0)
        ["blue"]=>
        int(0)
      }
    }
  }
}
