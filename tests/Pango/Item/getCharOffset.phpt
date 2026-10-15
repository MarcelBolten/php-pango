--TEST--
Pango\Item::getCharOffset()
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
var_dump($layout
  ->getLinesReadonly()[0] // only one line
  ->getRuns()[2] // the third run contains 1 Chinese character
  ->item
  ->getCharOffset()
);
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
int(10)
