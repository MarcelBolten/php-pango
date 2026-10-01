--TEST--
Pango\Attribute\AttributeList::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AttributeList;

$attributeList = new AttributeList();
var_dump($attributeList);

$attributeList2 = new AttributeList("10 20 size 42");
var_dump($attributeList2);

try {
     new AttributeList("\0");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new AttributeList("test", 123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new AttributeList(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new AttributeList("not a valid attribute list string");
} catch (Pango\Exception $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\AttributeList)#%d (0) {
}
object(Pango\Attribute\AttributeList)#%d (0) {
}
Pango\Attribute\AttributeList::__construct(): Argument #1 ($string) must not contain NUL bytes
Pango\Attribute\AttributeList::__construct() expects at most 1 argument, 2 given
Pango\Attribute\AttributeList::__construct(): Argument #1 ($string) must be of type ?string, array given
Failed to create Pango\Attribute\AttributeList from string
