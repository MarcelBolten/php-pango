--TEST--
Pango\Attribute\AttributeList::splice()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AttributeList;

$attributeList = new AttributeList("10 20 size 10");
$attributeList2 = new AttributeList("0 20 weight bold");

$work = clone $attributeList;
$work->splice($attributeList2, 15, 5);
var_dump($work->serialize());

$work = clone $attributeList;
$work->splice($attributeList2, 15, 0);
var_dump($work->serialize());

try {
    $attributeList->splice();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->splice($attributeList2);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->splice($attributeList2, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->splice($attributeList2, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->splice(array(), 0, 0);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->splice($attributeList2, array(), 2);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->splice($attributeList2, 1, array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
string(31) "10 25 size 10
15 20 weight bold"
string(31) "10 20 size 10
15 35 weight bold"
Pango\Attribute\AttributeList::splice() expects exactly 3 arguments, 0 given
Pango\Attribute\AttributeList::splice() expects exactly 3 arguments, 1 given
Pango\Attribute\AttributeList::splice() expects exactly 3 arguments, 2 given
Pango\Attribute\AttributeList::splice() expects exactly 3 arguments, 4 given
Pango\Attribute\AttributeList::splice(): Argument #1 ($other) must be of type Pango\Attribute\AttributeList, array given
Pango\Attribute\AttributeList::splice(): Argument #2 ($pos) must be of type int, array given
Pango\Attribute\AttributeList::splice(): Argument #3 ($length) must be of type int, array given
