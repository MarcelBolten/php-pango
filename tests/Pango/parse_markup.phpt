--TEST--
Pango\parse_markup()
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
?>
--FILE--
<?php
use function Pango\parse_markup;

$res = parse_markup('<span foreground="red">Hello</span> <span background="blue">World</span>');
var_dump($res);
var_dump($res->attrList->toString());

$res = parse_markup('<span foreground="red">_Hello</span> <span background="blue">World</span>', "_");
var_dump($res);
var_dump($res->attrList->toString());

try {
    parse_markup("\0Hello World");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    parse_markup("Hello World", "\0");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    parse_markup("Hello World", "__");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    parse_markup("<b>Hello World");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\MarkupParseResult)#%d (3) {
  ["attrList"]=>
  object(Pango\Attribute\AttributeList)#%d (0) {
  }
  ["text"]=>
  string(11) "Hello World"
  ["accelChar"]=>
  NULL
}
string(58) "0 5 foreground #ffff00000000
6 11 background #00000000ffff"
object(Pango\MarkupParseResult)#%d (3) {
  ["attrList"]=>
  object(Pango\Attribute\AttributeList)#%d (0) {
  }
  ["text"]=>
  string(11) "Hello World"
  ["accelChar"]=>
  string(1) "H"
}
string(76) "0 1 underline low
0 5 foreground #ffff00000000
6 11 background #00000000ffff"
Pango\parse_markup(): Argument #1 ($markup) must not contain NUL bytes
Pango\parse_markup(): Argument #2 ($accelMarker) must not contain NUL bytes
Pango\parse_markup(): Argument #2 ($accelMarker) must be a single UTF-8 character
Pango\parse_markup(): Argument #1 ($markup) Failed to parse markup: Error on line 1 char 31: Element “markup” was closed, but the currently open element is “b”
