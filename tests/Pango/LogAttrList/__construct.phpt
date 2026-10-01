--TEST--
Pango\LogAttrList::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\LogAttrList;
use Pango\Language;

$text = <<<EOT
Hello, Παν語!

This is a test of the Pango\LogAttrList class constructor.
It needs a bit of text to analyze, so here is some more text to make sure we have enough characters to analyze.
EOT;

var_dump(new LogAttrList($text));
var_dump(new LogAttrList($text, new Language("en")));
var_dump(new LogAttrList($text, new Language("en"), level: 0));

try {
    new LogAttrList($text . "\0");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new LogAttrList($text, level: -2);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new LogAttrList($text, level: PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new LogAttrList();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new LogAttrList($text, new Language("en"), 0, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new LogAttrList(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new LogAttrList($text, array(), level: 0);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new LogAttrList($text, new Language("en"), array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\LogAttrList)#%d (1) {
  ["text"]=>
  string(189) "Hello, Παν語!

This is a test of the Pango\LogAttrList class constructor.
It needs a bit of text to analyze, so here is some more text to make sure we have enough characters to analyze."
}
object(Pango\LogAttrList)#%d (1) {
  ["text"]=>
  string(189) "Hello, Παν語!

This is a test of the Pango\LogAttrList class constructor.
It needs a bit of text to analyze, so here is some more text to make sure we have enough characters to analyze."
}
object(Pango\LogAttrList)#%d (1) {
  ["text"]=>
  string(189) "Hello, Παν語!

This is a test of the Pango\LogAttrList class constructor.
It needs a bit of text to analyze, so here is some more text to make sure we have enough characters to analyze."
}
Pango\LogAttrList::__construct(): Argument #1 ($text) must not contain NUL bytes
Pango\LogAttrList::__construct(): Argument #3 ($level) must be between -1 and 2147483647
Pango\LogAttrList::__construct(): Argument #3 ($level) must be between -1 and 2147483647
Pango\LogAttrList::__construct() expects at least 1 argument, 0 given
Pango\LogAttrList::__construct() expects at most 3 arguments, 4 given
Pango\LogAttrList::__construct(): Argument #1 ($text) must be of type string, array given
Pango\LogAttrList::__construct(): Argument #2 ($language) must be of type ?Pango\Language, array given
Pango\LogAttrList::__construct(): Argument #3 ($level) must be of type int, array given