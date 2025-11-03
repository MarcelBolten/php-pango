--TEST--
Pango\LayoutLine::isParagraphStart()
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
var_dump($line->isParagraphStart());

$layout->setWidth(200 * Pango\Pango::SCALE);
$layout->setText("Hello, Παν語!\nThis is a new paragraph with more text that will be wrapped.");
var_dump($layout->getLineCount());
foreach ($layout->getLines() as $line) {
    var_dump($line->isParagraphStart());
}

try {
    $line->isParagraphStart(1);
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
bool(true)
int(4)
bool(true)
bool(true)
bool(false)
bool(false)
Pango\LayoutLine::isParagraphStart() expects exactly 0 arguments, 1 given
