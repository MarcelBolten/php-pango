--TEST--
Pango\reorder_items()
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AttributeList;
use Pango\Context;
use PangoCairo\FontMap;
use function Pango\reorder_items;

$fontMap = FontMap::getDefault();
var_dump($fontMap);
$context = new Context($fontMap);
var_dump($context);

$attrList = new AttributeList("0 8 size 16, 8 10 size 12, 10 16 size 14, 16 19 size 18, 19 20 size 16");
$attrIter = $attrList->getIterator();

$text = "שלום, Παν語!";
$item_arr = $context->itemize($text, 0, 20, $attrList, baseDir: Pango\Direction::RTL);

var_dump(count($item_arr));
var_dump($item_arr[0]);

$item_arr_reordered = reorder_items($item_arr);
var_dump(count($item_arr_reordered));
var_dump($item_arr_reordered[0]);

var_dump($item_arr[0]);

try {
    $item_arr[] = "test";
    reorder_items($item_arr);
} catch (TypeError $e) {
    echo $e->getMessage() . PHP_EOL;
}

try {
    reorder_items();
} catch (ArgumentCountError $e) {
    echo $e->getMessage() . PHP_EOL;
}

try {
    reorder_items($item_arr, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage() . PHP_EOL;
}

try {
    reorder_items(1);
} catch (TypeError $e) {
    echo $e->getMessage() . PHP_EOL;
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
int(5)
object(Pango\Item)#%d (4) {
  ["offset"]=>
  int(0)
  ["length"]=>
  int(8)
  ["numChars"]=>
  int(4)
  ["analysis"]=>
  object(Pango\Analysis)#%d (7) {
    ["font"]=>
    object(Pango\Font)#%d (1) {
      ["string-representation"]=>
      string(17) "DejaVu Sans 0.015"
    }
    ["level"]=>
    int(1)
    ["gravity"]=>
    enum(Pango\Gravity::South)
    ["flags"]=>
    int(128)
    ["script"]=>
    enum(Pango\Script::Hebrew)
    ["language"]=>
    object(Pango\Language)#%d (1) {
      ["string-representation"]=>
      string(1) "c"
    }
    ["extraAttrs"]=>
    array(0) {
    }
  }
}
int(5)
object(Pango\Item)#%d (4) {
  ["offset"]=>
  int(19)
  ["length"]=>
  int(1)
  ["numChars"]=>
  int(1)
  ["analysis"]=>
  object(Pango\Analysis)#%d (7) {
    ["font"]=>
    object(Pango\Font)#%d (1) {
      ["string-representation"]=>
      string(18) "DejaVu Serif 0.015"
    }
    ["level"]=>
    int(1)
    ["gravity"]=>
    enum(Pango\Gravity::South)
    ["flags"]=>
    int(128)
    ["script"]=>
    enum(Pango\Script::Han)
    ["language"]=>
    object(Pango\Language)#%d (1) {
      ["string-representation"]=>
      string(1) "c"
    }
    ["extraAttrs"]=>
    array(0) {
    }
  }
}
object(Pango\Item)#%d (4) {
  ["offset"]=>
  int(0)
  ["length"]=>
  int(8)
  ["numChars"]=>
  int(4)
  ["analysis"]=>
  object(Pango\Analysis)#%d (7) {
    ["font"]=>
    object(Pango\Font)#%d (1) {
      ["string-representation"]=>
      string(17) "DejaVu Sans 0.015"
    }
    ["level"]=>
    int(1)
    ["gravity"]=>
    enum(Pango\Gravity::South)
    ["flags"]=>
    int(128)
    ["script"]=>
    enum(Pango\Script::Hebrew)
    ["language"]=>
    object(Pango\Language)#%d (1) {
      ["string-representation"]=>
      string(1) "c"
    }
    ["extraAttrs"]=>
    array(0) {
    }
  }
}
Pango\reorder_items(): Argument #1 ($items) must be an array of Pango\Item objects
Pango\reorder_items() expects exactly 1 argument, 0 given
Pango\reorder_items() expects exactly 1 argument, 2 given
Pango\reorder_items(): Argument #1 ($items) must be of type array, int given
