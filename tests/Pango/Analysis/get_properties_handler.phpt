--TEST--
Pango\Analysis get_properties handler
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
$attrList = new Pango\Attribute\AttributeList("0 20 foreground red, 0 20 language en, 0 20 font-desc \"Sans 12\"");
$attrList->insert(new Pango\Attribute\ShapeAttribute(new Pango\Rectangle(0, 0, 10, 10), new Pango\Rectangle(0, 0, 10, 10)));
$layout->setAttributes($attrList);
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
    string(2) "en"
  }
  ["extraAttrs"]=>
  array(2) {
    [0]=>
    object(Pango\Attribute\ShapeAttribute)#%d (4) {
      ["startIndex"]=>
      int(0)
      ["endIndex"]=>
      int(4294967295)
      ["inkRect"]=>
      object(Pango\Rectangle)#%d (8) {
        ["x"]=>
        int(0)
        ["y"]=>
        int(0)
        ["width"]=>
        int(10)
        ["height"]=>
        int(10)
        ["ascent"]=>
        int(0)
        ["descent"]=>
        int(10)
        ["leftBearing"]=>
        int(0)
        ["rightBearing"]=>
        int(10)
      }
      ["logicalRect"]=>
      object(Pango\Rectangle)#%d (8) {
        ["x"]=>
        int(0)
        ["y"]=>
        int(0)
        ["width"]=>
        int(10)
        ["height"]=>
        int(10)
        ["ascent"]=>
        int(0)
        ["descent"]=>
        int(10)
        ["leftBearing"]=>
        int(0)
        ["rightBearing"]=>
        int(10)
      }
    }
    [1]=>
    object(Pango\Attribute\ForegroundAttribute)#%d (3) {
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
