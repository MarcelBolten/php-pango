--TEST--
Pango\Variant enum
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
?>
--FILE--
<?php
var_dump(Pango\Variant::cases());

var_dump(Pango\Variant::parse("Normal"));

try {
    var_dump(Pango\Variant::parse("invalid\0"));
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    var_dump(Pango\Variant::parse("invalid"));
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    var_dump(Pango\Variant::parse());
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    var_dump(Pango\Variant::parse("1", 2));
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
array(7) {
  [0]=>
  enum(Pango\Variant::Normal)
  [1]=>
  enum(Pango\Variant::SmallCaps)
  [2]=>
  enum(Pango\Variant::AllSmallCaps)
  [3]=>
  enum(Pango\Variant::PetiteCaps)
  [4]=>
  enum(Pango\Variant::AllPetiteCaps)
  [5]=>
  enum(Pango\Variant::Unicase)
  [6]=>
  enum(Pango\Variant::TitleCaps)
}
enum(Pango\Variant::Normal)
Pango\Variant::parse(): Argument #1 ($string) must not contain NUL bytes
Pango\Variant::parse(): Argument #1 ($string) is not a valid Pango variant
Pango\Variant::parse() expects exactly 1 argument, 0 given
Pango\Variant::parse() expects exactly 1 argument, 2 given
