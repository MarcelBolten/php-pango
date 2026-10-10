--TEST--
Pango\Attribute\Style::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Style;

$style = new Style(Pango\Style::Italic);
var_dump($style);

try {
    new Style();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Style(Pango\Style::Italic, 1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Style(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\Style)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Style::Italic)
}
Pango\Attribute\Style::__construct() expects at least 1 argument, 0 given
Pango\Attribute\Style::__construct() expects at most 3 arguments, 4 given
Pango\Attribute\Style::__construct(): Argument #1 ($value) must be of type Pango\Style, array given
