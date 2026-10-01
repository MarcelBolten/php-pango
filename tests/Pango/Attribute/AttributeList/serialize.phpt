--TEST--
Pango\Attribute\AttributeList::serialize()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AttributeList;
use Pango\Attribute\Size;

$attributeList = new AttributeList();
var_dump($attributeList->getAttributes());

$attrSize = new Size(10);
$attrSize->startIndex = 10;
$attrSize->endIndex = 20;
$attributeList->insert($attrSize);

var_dump($attributeList->getAttributes());
var_dump($attributeList->serialize());

try {
    $attributeList->serialize(123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
array(0) {
}
array(1) {
  [0]=>
  object(Pango\Attribute\Size)#%d (3) {
    ["startIndex"]=>
    int(10)
    ["endIndex"]=>
    int(20)
    ["value"]=>
    int(10)
  }
}
string(13) "10 20 size 10"
Pango\Attribute\AttributeList::serialize() expects exactly 0 arguments, 1 given
