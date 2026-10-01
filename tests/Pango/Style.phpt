--TEST--
Pango\Style enum
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
?>
--FILE--
<?php
var_dump(Pango\Style::cases());

var_dump(Pango\Style::parse("Normal"));

try {
    var_dump(Pango\Style::parse("invalid\0"));
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    var_dump(Pango\Style::parse("invalid"));
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    var_dump(Pango\Style::parse());
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    var_dump(Pango\Style::parse("1", 2));
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
array(3) {
  [0]=>
  enum(Pango\Style::Normal)
  [1]=>
  enum(Pango\Style::Oblique)
  [2]=>
  enum(Pango\Style::Italic)
}
enum(Pango\Style::Normal)
Pango\Style::parse(): Argument #1 ($string) must not contain NUL bytes
Pango\Style::parse(): Argument #1 ($string) is not a valid Pango style
Pango\Style::parse() expects exactly 1 argument, 0 given
Pango\Style::parse() expects exactly 1 argument, 2 given
