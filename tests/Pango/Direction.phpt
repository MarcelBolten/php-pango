--TEST--
Pango\Direction enum
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
?>
--FILE--
<?php
var_dump(Pango\Direction::cases());

// var_dump(Pango\Direction::findBaseDir("Hello, Παν語!"));
// var_dump(Pango\Direction::findBaseDir("שלום, Παν語!"));
// var_dump(Pango\Direction::findBaseDir("🐘"));

// try {
//     var_dump(Pango\Direction::findBaseDir("invalid\0"));
// } catch (ValueError $e) {
//     echo $e->getMessage(), "\n";
// }

// try {
//     var_dump(Pango\Direction::findBaseDir());
// } catch (ArgumentCountError $e) {
//     echo $e->getMessage(), "\n";
// }

// try {
//     var_dump(Pango\Direction::findBaseDir("1", 2));
// } catch (ArgumentCountError $e) {
//     echo $e->getMessage(), "\n";
// }

// try {
//     var_dump(Pango\Direction::findBaseDir(array()));
// } catch (TypeError $e) {
//     echo $e->getMessage(), "\n";
// }

// --EXPECTF--
// enum(Pango\Direction::LTR)
// enum(Pango\Direction::RTL)
// enum(Pango\Direction::Neutral)
// Pango\Direction::findBaseDir(): Argument #1 ($text) must not contain NUL bytes
// Pango\Direction::findBaseDir() expects exactly 1 argument, 0 given
// Pango\Direction::findBaseDir() expects exactly 1 argument, 2 given
// Pango\Direction::findBaseDir(): Argument #1 ($text) must be of type string, array given

?>
--EXPECTF--
array(5) {
  [0]=>
  enum(Pango\Direction::LTR)
  [1]=>
  enum(Pango\Direction::RTL)
  [2]=>
  enum(Pango\Direction::WeakLTR)
  [3]=>
  enum(Pango\Direction::WeakRTL)
  [4]=>
  enum(Pango\Direction::Neutral)
}
