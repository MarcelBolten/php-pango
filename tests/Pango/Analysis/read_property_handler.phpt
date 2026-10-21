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
$layout->setAttributes(new Pango\Attribute\AttributeList("0 20 rise 44, 0 20 language en, 0 20 font-desc \"Sans 12\""));

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
array(1) {
  [0]=>
  object(Pango\Attribute\RiseAttribute)#%d (3) {
    ["startIndex"]=>
    int(0)
    ["endIndex"]=>
    int(20)
    ["value"]=>
    int(44)
  }
}
