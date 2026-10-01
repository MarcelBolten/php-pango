--TEST--
Pango\Weight enum
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
?>
--FILE--
<?php
var_dump(Pango\Weight::cases());

var_dump(Pango\Weight::parse("Normal"));

try {
    var_dump(Pango\Weight::parse("invalid\0"));
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    var_dump(Pango\Weight::parse("invalid"));
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    var_dump(Pango\Weight::parse());
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    var_dump(Pango\Weight::parse("1", 2));
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
array(12) {
  [0]=>
  enum(Pango\Weight::Thin)
  [1]=>
  enum(Pango\Weight::UltraLight)
  [2]=>
  enum(Pango\Weight::Light)
  [3]=>
  enum(Pango\Weight::SemiLight)
  [4]=>
  enum(Pango\Weight::Book)
  [5]=>
  enum(Pango\Weight::Normal)
  [6]=>
  enum(Pango\Weight::Medium)
  [7]=>
  enum(Pango\Weight::SemiBold)
  [8]=>
  enum(Pango\Weight::Bold)
  [9]=>
  enum(Pango\Weight::UltraBold)
  [10]=>
  enum(Pango\Weight::Heavy)
  [11]=>
  enum(Pango\Weight::UltraHeavy)
}
enum(Pango\Weight::Normal)
Pango\Weight::parse(): Argument #1 ($string) must not contain NUL bytes
Pango\Weight::parse(): Argument #1 ($string) is not a valid Pango weight
Pango\Weight::parse() expects exactly 1 argument, 0 given
Pango\Weight::parse() expects exactly 1 argument, 2 given
