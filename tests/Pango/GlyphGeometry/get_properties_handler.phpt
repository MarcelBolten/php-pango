--TEST--
Pango\GlyphGeometry get_properties handler
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
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
object(Pango\GlyphGeometry)#%d (3) {
  ["width"]=>
  int(11264)
  ["xOffset"]=>
  int(0)
  ["yOffset"]=>
  int(0)
}
