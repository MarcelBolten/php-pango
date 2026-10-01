--TEST--
Pango\ScriptIterRange::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\ScriptIterRange;
use Pango\Script;

var_dump(new ScriptIterRange("Text", 0, 4, Script::Latin));

try {
    new ScriptIterRange("Text\0", 0, 4, Script::Latin);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ScriptIterRange();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ScriptIterRange("Text", 0);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ScriptIterRange("Text", 0, 4);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ScriptIterRange("Text", 0, 4, Script::Latin, "extra");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ScriptIterRange(array(), 0, 4, Script::Latin);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ScriptIterRange("Text", array(), 4, Script::Latin);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ScriptIterRange("Text", 0, array(), Script::Latin);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new ScriptIterRange("Text", 0, 4, array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\ScriptIterRange)#%d (4) {
  ["text"]=>
  string(4) "Text"
  ["byteStart"]=>
  int(0)
  ["byteEnd"]=>
  int(4)
  ["script"]=>
  enum(Pango\Script::Latin)
}
Pango\ScriptIterRange::__construct(): Argument #1 ($text) must not contain NUL bytes
Pango\ScriptIterRange::__construct() expects exactly 4 arguments, 0 given
Pango\ScriptIterRange::__construct() expects exactly 4 arguments, 2 given
Pango\ScriptIterRange::__construct() expects exactly 4 arguments, 3 given
Pango\ScriptIterRange::__construct() expects exactly 4 arguments, 5 given
Pango\ScriptIterRange::__construct(): Argument #1 ($text) must be of type string, array given
Pango\ScriptIterRange::__construct(): Argument #2 ($byteStart) must be of type int, array given
Pango\ScriptIterRange::__construct(): Argument #3 ($byteEnd) must be of type int, array given
Pango\ScriptIterRange::__construct(): Argument #4 ($script) must be of type Pango\Script, array given
