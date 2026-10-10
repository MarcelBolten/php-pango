--TEST--
Pango\Attribute\Sentence::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Sentence;

$sentence = new Sentence();
var_dump($sentence);

try {
    new Sentence(1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\Sentence)#%d (2) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
}
Pango\Attribute\Sentence::__construct() expects at most 2 arguments, 3 given
