--TEST--
Pango\Attribute\TextTransform::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\TextTransform;

$textTransform = new TextTransform(Pango\TextTransform::Lowercase);
var_dump($textTransform);

try {
    new TextTransform();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new TextTransform(Pango\TextTransform::Lowercase, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new TextTransform(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\TextTransform)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\TextTransform::Lowercase)
}
Pango\Attribute\TextTransform::__construct() expects at least 1 argument, 0 given
Pango\Attribute\TextTransform::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\TextTransform::__construct(): Argument #1 ($value) must be of type Pango\TextTransform, array given
