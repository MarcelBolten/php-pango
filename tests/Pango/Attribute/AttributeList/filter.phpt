--TEST--
Pango\Attribute\AttributeList::filter()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AttributeList;

$callback = function (Pango\Attribute\Attribute $attr): bool {
    return $attr instanceof Pango\Attribute\Size;
};

$notSizeCallback = function (Pango\Attribute\Attribute $attr): bool {
    return !($attr instanceof Pango\Attribute\Size);
};

$attributeList = new AttributeList("10 20 size 42, 10 20 weight bold");
var_dump($attributeList);

$filterResult = $attributeList->filter($callback);
// The original list should now only contain the weight attribute.
var_dump($attributeList->getAttributes());
// The new list should only contain the size attribute.
var_dump($filterResult->getAttributes());

$emptyResult = $attributeList->filter($callback);
// The original list should still only contain the weight attribute.
var_dump($attributeList->getAttributes());
// Should be NULL since there are no size attributes left in the original list.
var_dump($emptyResult);

var_dump((new AttributeList("10 20 size 42, language en, font-desc \"Sans 10\""))
    ->filter($notSizeCallback)->toString());

// callback must return a boolean value
try {
    (new AttributeList("10 20 size 42, 10 20 weight bold"))
        ->filter(fn (Pango\Attribute\Attribute $attr): int => 1);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

// throwing an exception in the callback will propagate the exception to the caller and leave the original list unchanged
try {
    $attributeList = new AttributeList("10 20 size 42, 10 20 weight bold");
    $attributeList->filter(fn (Pango\Attribute\Attribute $attr): bool => throw new Exception("exception in callback"));
} catch (Exception $e) {
    var_dump($attributeList->toString());
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->filter();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->filter($callback, 2);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $attributeList->filter(1);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\AttributeList)#%d (0) {
}
array(1) {
  [0]=>
  object(Pango\Attribute\Weight)#%d (3) {
    ["startIndex"]=>
    int(10)
    ["endIndex"]=>
    int(20)
    ["value"]=>
    enum(Pango\Weight::Bold)
  }
}
array(1) {
  [0]=>
  object(Pango\Attribute\Size)#%d (3) {
    ["startIndex"]=>
    int(10)
    ["endIndex"]=>
    int(20)
    ["value"]=>
    int(42)
  }
}
array(1) {
  [0]=>
  object(Pango\Attribute\Weight)#%d (3) {
    ["startIndex"]=>
    int(10)
    ["endIndex"]=>
    int(20)
    ["value"]=>
    enum(Pango\Weight::Bold)
  }
}
NULL
string(57) "0 4294967295 language en
0 4294967295 font-desc "Sans 10""
Pango\Attribute\AttributeList::filter(): Argument #1 ($callback) must return a boolean value
string(31) "10 20 size 42
10 20 weight bold"
exception in callback
Pango\Attribute\AttributeList::filter() expects exactly 1 argument, 0 given
Pango\Attribute\AttributeList::filter() expects exactly 1 argument, 2 given
Pango\Attribute\AttributeList::filter(): Argument #1 ($callback) must be a valid callback, no array or string given
