--TEST--
Pango\GlyphItem::getLogicalWidths()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$layout = (new PangoCairo\Layout($cairoContext))
    ->setText("Hello, Παν語!");
var_dump($layout);

$runs = $layout->getLine(0)->getRuns();
$glyphItem = $runs[1];
var_dump($glyphItem->getLogicalWidths());

try {
    $glyphItem->getLogicalWidths(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
array(3) {
  [0]=>
  int(14336)
  [1]=>
  int(11264)
  [2]=>
  int(10240)
}
Pango\GlyphItem::getLogicalWidths() expects exactly 0 arguments, 1 given
