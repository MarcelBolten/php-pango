--TEST--
Pango\Stretch enum
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
?>
--FILE--
<?php
var_dump(Pango\Stretch::cases());

var_dump(Pango\Stretch::parse("Normal"));

try {
    var_dump(Pango\Stretch::parse("invalid\0"));
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    var_dump(Pango\Stretch::parse("invalid"));
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    var_dump(Pango\Stretch::parse());
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    var_dump(Pango\Stretch::parse("1", 2));
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
array(9) {
  [0]=>
  enum(Pango\Stretch::UltraCondensed)
  [1]=>
  enum(Pango\Stretch::ExtraCondensed)
  [2]=>
  enum(Pango\Stretch::Condensed)
  [3]=>
  enum(Pango\Stretch::SemiCondensed)
  [4]=>
  enum(Pango\Stretch::Normal)
  [5]=>
  enum(Pango\Stretch::SemiExpanded)
  [6]=>
  enum(Pango\Stretch::Expanded)
  [7]=>
  enum(Pango\Stretch::ExtraExpanded)
  [8]=>
  enum(Pango\Stretch::UltraExpanded)
}
enum(Pango\Stretch::Normal)
Pango\Stretch::parse(): Argument #1 ($string) must not contain NUL bytes
Pango\Stretch::parse(): Argument #1 ($string) is not a valid Pango stretch
Pango\Stretch::parse() expects exactly 1 argument, 0 given
Pango\Stretch::parse() expects exactly 1 argument, 2 given
