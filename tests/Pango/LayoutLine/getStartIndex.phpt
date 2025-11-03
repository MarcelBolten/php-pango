--TEST--
Pango\LayoutLine::getStartIndex()
--EXTENSIONS--
pango
cairo
--FILE--
<?php
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);

$pangoContext = new Pango\Context($fontMap);
var_dump($pangoContext);

$layout = new Pango\Layout($pangoContext);
var_dump($layout);

$line = $layout->getLineReadonly(0);
var_dump($line);
var_dump($line->getStartIndex());

$layout->setText("Hello,\nΠαν語!\n");
foreach ($layout->getLines() as $line) {
    var_dump($line->getStartIndex());
}

try {
    $line->getStartIndex(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
object(Pango\LayoutLine)#%d (0) {
}
int(0)
int(0)
int(7)
int(18)
Pango\LayoutLine::getStartIndex() expects exactly 0 arguments, 1 given
