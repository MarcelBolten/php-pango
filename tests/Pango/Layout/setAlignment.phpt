--TEST--
Pango\Layout::setAlignment()
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

var_dump($layout->getAlignment());

$layout->setAlignment(Pango\Alignment::Center);
var_dump($layout->getAlignment());

try {
    $layout->setAlignment();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setAlignment(Pango\Alignment::Right, 'wrong');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setAlignment('left');
} catch (TypeError $e) {
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
enum(Pango\Alignment::Left)
enum(Pango\Alignment::Center)
Pango\Layout::setAlignment() expects exactly 1 argument, 0 given
Pango\Layout::setAlignment() expects exactly 1 argument, 2 given
Pango\Layout::setAlignment(): Argument #1 ($alignment) must be of type Pango\Alignment, string given
