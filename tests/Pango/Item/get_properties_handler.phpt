--TEST--
Pango\Item get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Ft2\FontMap;
use Pango\Context;
use Pango\Layout;

$fontMap = new FontMap();
var_dump($fontMap);
$context = new Context($fontMap);
var_dump($context);
$layout = new Layout($context);
var_dump($layout);

$layout->setText("Hello, Παν語!");
var_dump($layout->getLine(0)->getRuns()[1]->item);
?>
--EXPECTF--
object(Pango\Ft2\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
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
      string(%d) "%s"
    }
    ["extraAttrs"]=>
    array(0) {
    }
  }
}
