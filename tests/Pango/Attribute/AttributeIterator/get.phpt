--TEST--
Pango\Attribute\AttributeIterator::getAttributes()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\AttributeList;
use Pango\Attribute\AttributeType;
use Pango\Attribute\ShapeAttribute;
use Pango\Rectangle;

$attrList = new AttributeList('0 10 size 42, 0 5 font-desc "Sans 12", 0 2 language en');
$rect = new Rectangle(0, 0, 100, 100);
$shapeAttr = new ShapeAttribute($rect, $rect);
$attrList->insert($shapeAttr);
var_dump($attrList);
$attrIter = $attrList->getIterator();
var_dump($attrIter);
var_dump($attrIter->get(AttributeType::Size));
var_dump($attrIter->get(AttributeType::FontDesc));
var_dump($attrIter->get(AttributeType::Language));
var_dump($attrIter->get(AttributeType::Shape));
var_dump($attrIter->get(AttributeType::Rise));

try {
    $attrIter->get();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attrIter->get(AttributeType::Size, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attrIter->get(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\AttributeList)#%d (0) {
}
object(Pango\Attribute\AttributeIterator)#%d (0) {
}
object(Pango\Attribute\SizeAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(10)
  ["value"]=>
  int(42)
}
object(Pango\Attribute\FontDescriptionAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(5)
  ["desc"]=>
  object(Pango\FontDescription)#%d (0) {
  }
}
object(Pango\Attribute\LanguageAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(2)
  ["value"]=>
  object(Pango\Language)#%d (1) {
    ["string-representation"]=>
    string(2) "en"
  }
}
object(Pango\Attribute\ShapeAttribute)#%d (4) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["inkRect"]=>
  object(Pango\Rectangle)#%d (8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(0)
    ["width"]=>
    int(100)
    ["height"]=>
    int(100)
    ["ascent"]=>
    int(0)
    ["descent"]=>
    int(100)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(100)
  }
  ["logicalRect"]=>
  object(Pango\Rectangle)#%d (8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(0)
    ["width"]=>
    int(100)
    ["height"]=>
    int(100)
    ["ascent"]=>
    int(0)
    ["descent"]=>
    int(100)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(100)
  }
}
NULL
Pango\Attribute\AttributeIterator::get() expects exactly 1 argument, 0 given
Pango\Attribute\AttributeIterator::get() expects exactly 1 argument, 2 given
Pango\Attribute\AttributeIterator::get(): Argument #1 ($type) must be of type Pango\Attribute\AttributeType, array given
