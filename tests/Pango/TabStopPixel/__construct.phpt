--TEST--
Pango\TabStopPixel::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\TabStopPixel;
use Pango\TabAlign;

var_dump(new TabStopPixel(TabAlign::Right, 10240));
var_dump(new TabStopPixel(TabAlign::Decimal, 10240, "."));

try {
    new TabStopPixel();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new TabStopPixel(TabAlign::Right);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new TabStopPixel(TabAlign::Right, 10240, ".", 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new TabStopPixel(array(), 10240, ".");
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new TabStopPixel(TabAlign::Right, array(), ".");
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new TabStopPixel(TabAlign::Right, 10240, array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\TabStopPixel)#%d (3) {
  ["alignment"]=>
  enum(Pango\TabAlign::Right)
  ["position"]=>
  int(10240)
  ["decimalChar"]=>
  NULL
}
object(Pango\TabStopPixel)#%d (3) {
  ["alignment"]=>
  enum(Pango\TabAlign::Decimal)
  ["position"]=>
  int(10240)
  ["decimalChar"]=>
  string(1) "."
}
Pango\TabStop::__construct() expects at least 2 arguments, 0 given
Pango\TabStop::__construct() expects at least 2 arguments, 1 given
Pango\TabStop::__construct() expects at most 3 arguments, 4 given
Pango\TabStop::__construct(): Argument #1 ($alignment) must be of type Pango\TabAlign, array given
Pango\TabStop::__construct(): Argument #2 ($position) must be of type int, array given
Pango\TabStop::__construct(): Argument #3 ($decimalChar) must be of type ?string, array given
