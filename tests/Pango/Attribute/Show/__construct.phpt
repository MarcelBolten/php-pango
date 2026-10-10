--TEST--
Pango\Attribute\Show::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Show;

$show = new Show(Show::NONE);
var_dump($show);

try {
    new Show(-1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Show(8);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Show();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Show(Show::NONE, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Show(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\Show)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(0)
}
Pango\Attribute\Show::__construct(): Argument #1 ($value) must be a class constant of Pango\Attribute\Show or a combination of them
Pango\Attribute\Show::__construct(): Argument #1 ($value) must be a class constant of Pango\Attribute\Show or a combination of them
Pango\Attribute\Show::__construct() expects at least 1 argument, 0 given
Pango\Attribute\Show::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\Show::__construct(): Argument #1 ($value) must be of type int, array given
