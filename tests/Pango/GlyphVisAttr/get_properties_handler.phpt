--TEST--
Pango\GlyphVisAttr get_properties handler
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
$attributes = $layout->getLineReadonly(0)->getRuns()[1]->glyphs->glyphs[1]->attributes;
var_dump($attributes);
// foreach(get_object_vars($attributes) as $name => $value) {
//     echo $name, ": ", get_debug_type($value), "\n";
// }
// isClusterStart: bool
// isColor: bool
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
object(Pango\GlyphVisAttr)#%d (2) {
  ["isClusterStart"]=>
  bool(true)
  ["isColor"]=>
  bool(false)
}
