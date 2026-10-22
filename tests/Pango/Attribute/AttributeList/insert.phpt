--TEST--
Pango\Attribute\AttributeList::insert()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\AttributeList;
use Pango\Attribute\LanguageAttribute;
use Pango\Attribute\FontDescriptionAttribute;
use Pango\Attribute\ShapeAttribute;
use Pango\Attribute\SizeAttribute;
use Pango\FontDescription;
use Pango\Language;
use Pango\Rectangle;

$attributeList = new AttributeList("10 20 size 42");
var_dump($attributeList->getAttributes());

$attrSize = new SizeAttribute(10, 10, 20);
$rect = new Rectangle(0, 0, 100, 100);
$shapeAttr = new ShapeAttribute($rect, $rect);
$langAttr = new LanguageAttribute(new Language("en"));
$fontDescAttr = new FontDescriptionAttribute(new FontDescription("Sans 12"));

$attributeList
  ->insert($attrSize)
  ->insert($shapeAttr)
  ->insert($langAttr)
  ->insert($fontDescAttr);

var_dump($attributeList->getAttributes());

try {
    $attributeList->insert();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->insert($attrSize, 123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->insert(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

?>
--EXPECTF--
array(1) {
  [0]=>
  object(Pango\Attribute\SizeAttribute)#%d (3) {
    ["startIndex"]=>
    int(10)
    ["endIndex"]=>
    int(20)
    ["value"]=>
    int(42)
  }
}
array(5) {
  [0]=>
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
  [1]=>
  object(Pango\Attribute\LanguageAttribute)#%d (3) {
    ["startIndex"]=>
    int(0)
    ["endIndex"]=>
    int(4294967295)
    ["value"]=>
    object(Pango\Language)#%d (1) {
      ["string-representation"]=>
      string(2) "en"
    }
  }
  [2]=>
  object(Pango\Attribute\FontDescriptionAttribute)#%d (3) {
    ["startIndex"]=>
    int(0)
    ["endIndex"]=>
    int(4294967295)
    ["desc"]=>
    object(Pango\FontDescription)#%d (0) {
    }
  }
  [3]=>
  object(Pango\Attribute\SizeAttribute)#%d (3) {
    ["startIndex"]=>
    int(10)
    ["endIndex"]=>
    int(20)
    ["value"]=>
    int(42)
  }
  [4]=>
  object(Pango\Attribute\SizeAttribute)#%d (3) {
    ["startIndex"]=>
    int(10)
    ["endIndex"]=>
    int(20)
    ["value"]=>
    int(10)
  }
}
Pango\Attribute\AttributeList::insert() expects exactly 1 argument, 0 given
Pango\Attribute\AttributeList::insert() expects exactly 1 argument, 2 given
Pango\Attribute\AttributeList::insert(): Argument #1 ($attr) must be of type Pango\Attribute\Attribute, array given
