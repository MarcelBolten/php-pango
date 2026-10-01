--TEST--
Pango\Layout::setAttributes()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
use PangoCairo\FontMap;
use Pango\Attribute\AttributeList;

$fontMap = FontMap::getDefault();
var_dump($fontMap);

$pangoContext = new Pango\Context($fontMap);
var_dump($pangoContext);

$layout = new Pango\Layout($pangoContext);
var_dump($layout);

var_dump($layout->getAttributes());

$attrList = new AttributeList("10 20 size 42");
$layout->setAttributes($attrList);

$attrList1 = $layout->getAttributes();
var_dump($attrList1);
var_dump($attrList1->getAttributes());

$layout->setAttributes();
$attrList2 = $layout->getAttributes();
var_dump($attrList2);

try {
    $layout->setAttributes($attrList, 'wrong');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setAttributes(array());
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
object(Pango\Attribute\AttributeList)#%d (0) {
}
array(1) {
  [0]=>
  object(Pango\Attribute\Size)#6 (3) {
    ["startIndex"]=>
    int(10)
    ["endIndex"]=>
    int(20)
    ["value"]=>
    int(42)
  }
}
NULL
Pango\Layout::setAttributes() expects at most 1 argument, 2 given
Pango\Layout::setAttributes(): Argument #1 ($attributes) must be of type ?Pango\Attribute\AttributeList, array given
