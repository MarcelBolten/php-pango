--TEST--
Pango\Attribute\Stretch::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Stretch;

$stretch = new Stretch(Pango\Stretch::Expanded);
var_dump($stretch);

try {
    new Stretch();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Stretch(Pango\Stretch::Expanded, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Stretch(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\Stretch)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Stretch::Expanded)
}
Pango\Attribute\Stretch::__construct() expects at least 1 argument, 0 given
Pango\Attribute\Stretch::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\Stretch::__construct(): Argument #1 ($value) must be of type Pango\Stretch, array given
