--TEST--
Pango\Analysis read property handler
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

foreach ($layout->getLinesReadonly() as $line) {
    $analysis = $line->getRuns()[1]->item->analysis;
    var_dump($analysis->font);
    var_dump($analysis->level);
    var_dump($analysis->gravity);
    /**
     * Pango internally uses bit 7 (0x80) to
     * indicate that the analysis is associated with an internal
     * PangoItemPrivate representation.
     */
    var_dump($analysis->flags);
    var_dump($analysis->script);
    var_dump($analysis->language->__toString());
    var_dump($analysis->extraAttrs);
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
object(Pango\Font)#%d (1) {
  ["string-representation"]=>
  string(%d) "%s"
}
int(0)
enum(Pango\Gravity::South)
int(128)
enum(Pango\Script::Greek)
string(2) "en"
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
