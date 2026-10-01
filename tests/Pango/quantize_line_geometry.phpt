--TEST--
Pango\quantize_line_geometry()
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
?>
--FILE--
<?php
use function Pango\quantize_line_geometry;

var_dump(quantize_line_geometry(512, 10240));

try {
    quantize_line_geometry(PHP_INT_MIN, 0);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    quantize_line_geometry(PHP_INT_MAX, 0);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    quantize_line_geometry(0, PHP_INT_MIN);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    quantize_line_geometry(0, PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    quantize_line_geometry();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    quantize_line_geometry(0, 1, 2);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    quantize_line_geometry(array(), 0);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
try {
    quantize_line_geometry(0, array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\QuantizedLineGeometry)#%d (2) {
  ["thickness"]=>
  int(1024)
  ["position"]=>
  int(10240)
}
Pango\quantize_line_geometry(): Argument #1 ($thickness) must be a between -2147483648 and 2147483647
Pango\quantize_line_geometry(): Argument #1 ($thickness) must be a between -2147483648 and 2147483647
Pango\quantize_line_geometry(): Argument #2 ($position) must be a between -2147483648 and 2147483647
Pango\quantize_line_geometry(): Argument #2 ($position) must be a between -2147483648 and 2147483647
Pango\quantize_line_geometry() expects exactly 2 arguments, 0 given
Pango\quantize_line_geometry() expects exactly 2 arguments, 3 given
Pango\quantize_line_geometry(): Argument #1 ($thickness) must be of type int, array given
Pango\quantize_line_geometry(): Argument #2 ($position) must be of type int, array given
