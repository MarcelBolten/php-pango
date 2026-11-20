--TEST--
Pango\GlyphGeometry get_properties handler
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
$geometry = $layout->getLineReadonly(0)->getRuns()[1]->glyphs->glyphs[1]->geometry;
var_dump($geometry);
// foreach(get_object_vars($geometry) as $name => $value) {
//     echo $name, ": ", get_debug_type($value), "\n";
// }

// width: int
// xOffset: int
// yOffset: int
?>
--EXPECTF--
object(Pango\Ft2\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
object(Pango\GlyphGeometry)#%d (3) {
  ["width"]=>
  int(%i)
  ["xOffset"]=>
  int(%i)
  ["yOffset"]=>
  int(%i)
}
