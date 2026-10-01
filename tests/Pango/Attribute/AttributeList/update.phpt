--TEST--
Pango\Attribute\AttributeList::update()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AttributeList;

$attributeList = new AttributeList("10 20 size 10");

$work = clone $attributeList;
$work->update(10, 11, 1);
var_dump($work->serialize());

$work = clone $attributeList;
$work->update(15, 5, 10);
var_dump($work->serialize());

$work = clone $attributeList;
$work->update(10, 5, 10);
var_dump($work->serialize());

$work = clone $attributeList;
$work->update(10, 5, 5);
var_dump($work->serialize());

$work = clone $attributeList;
$work->update(15, 6, 6);
var_dump($work->serialize());

try {
    $attributeList->update();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->update(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->update(1, 2);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->update(1, 2, 3, 4);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->update(array(), 2, 3);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->update(1, array(), 3);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->update(1, 2, array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
string(0) ""
string(13) "10 25 size 10"
string(13) "20 25 size 10"
string(13) "15 20 size 10"
string(13) "10 15 size 10"
Pango\Attribute\AttributeList::update() expects exactly 3 arguments, 0 given
Pango\Attribute\AttributeList::update() expects exactly 3 arguments, 1 given
Pango\Attribute\AttributeList::update() expects exactly 3 arguments, 2 given
Pango\Attribute\AttributeList::update() expects exactly 3 arguments, 4 given
Pango\Attribute\AttributeList::update(): Argument #1 ($pos) must be of type int, array given
Pango\Attribute\AttributeList::update(): Argument #2 ($remove) must be of type int, array given
Pango\Attribute\AttributeList::update(): Argument #3 ($add) must be of type int, array given
