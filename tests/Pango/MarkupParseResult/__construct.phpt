--TEST--
Pango\MarkupParseResult::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\MarkupParseResult;

var_dump(new MarkupParseResult(new Pango\Attribute\AttributeList(), "test", "t"));
var_dump(new MarkupParseResult(new Pango\Attribute\AttributeList(), "test"));

try {
    new MarkupParseResult(new Pango\Attribute\AttributeList(), "test\0");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new MarkupParseResult(new Pango\Attribute\AttributeList(), "test", "\0");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new MarkupParseResult(new Pango\Attribute\AttributeList(), "test", "12");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new MarkupParseResult();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new MarkupParseResult(new Pango\Attribute\AttributeList());
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new MarkupParseResult(new Pango\Attribute\AttributeList(), "test", "t", 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new MarkupParseResult(array(), "test", "t");
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new MarkupParseResult(new Pango\Attribute\AttributeList(), array(), "t");
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new MarkupParseResult(new Pango\Attribute\AttributeList(), "_test", array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\MarkupParseResult)#%d (3) {
  ["attrList"]=>
  object(Pango\Attribute\AttributeList)#%d (0) {
  }
  ["text"]=>
  string(4) "test"
  ["accelChar"]=>
  string(1) "t"
}
object(Pango\MarkupParseResult)#%d (3) {
  ["attrList"]=>
  object(Pango\Attribute\AttributeList)#%d (0) {
  }
  ["text"]=>
  string(4) "test"
  ["accelChar"]=>
  NULL
}
Pango\MarkupParseResult::__construct(): Argument #2 ($text) must not contain NUL bytes
Pango\MarkupParseResult::__construct(): Argument #3 ($accelChar) must not contain NUL bytes
Pango\MarkupParseResult::__construct(): Argument #3 ($accelChar) must be a single UTF-8 character
Pango\MarkupParseResult::__construct() expects at least 2 arguments, 0 given
Pango\MarkupParseResult::__construct() expects at least 2 arguments, 1 given
Pango\MarkupParseResult::__construct() expects at most 3 arguments, 4 given
Pango\MarkupParseResult::__construct(): Argument #1 ($attrList) must be of type Pango\Attribute\AttributeList, array given
Pango\MarkupParseResult::__construct(): Argument #2 ($text) must be of type string, array given
Pango\MarkupParseResult::__construct(): Argument #3 ($accelChar) must be of type ?string, array given
