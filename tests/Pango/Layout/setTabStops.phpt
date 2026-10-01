--TEST--
Pango\Layout::setTabStops()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
use PangoCairo\FontMap;
use Pango\TabStops;

$fontMap = FontMap::getDefault();
var_dump($fontMap);

$pangoContext = new Pango\Context($fontMap);
var_dump($pangoContext);

$layout = new Pango\Layout($pangoContext);
var_dump($layout);

var_dump($layout->getTabStops());

$layout->setTabStops(TabStops::fromString('left:100px right:200px center:300px decimal:400px:46'));

$tabStops = $layout->getTabStops();
var_dump($tabStops);
var_dump($tabStops->getTabs());

$layout->setTabStops();
$tabStops2 = $layout->getTabStops();
var_dump($tabStops2);

try {
    $layout->setTabStops($tabStops, 'wrong');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setTabStops(array());
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
NULL
object(Pango\TabStops)#%d (0) {
}
array(4) {
  [0]=>
  object(Pango\TabStopPixel)#%d (3) {
    ["alignment"]=>
    enum(Pango\TabAlign::Left)
    ["position"]=>
    int(100)
    ["decimalChar"]=>
    NULL
  }
  [1]=>
  object(Pango\TabStopPixel)#%d (3) {
    ["alignment"]=>
    enum(Pango\TabAlign::Right)
    ["position"]=>
    int(200)
    ["decimalChar"]=>
    NULL
  }
  [2]=>
  object(Pango\TabStopPixel)#%d (3) {
    ["alignment"]=>
    enum(Pango\TabAlign::Center)
    ["position"]=>
    int(300)
    ["decimalChar"]=>
    NULL
  }
  [3]=>
  object(Pango\TabStopPixel)#%d (3) {
    ["alignment"]=>
    enum(Pango\TabAlign::Decimal)
    ["position"]=>
    int(400)
    ["decimalChar"]=>
    string(1) "."
  }
}
NULL
Pango\Layout::setTabStops() expects at most 1 argument, 2 given
Pango\Layout::setTabStops(): Argument #1 ($tabStops) must be of type ?Pango\TabStops, array given
