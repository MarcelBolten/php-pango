--TEST--
Pango\units_to_double()
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
?>
--FILE--
<?php
use function Pango\units_to_double;

var_dump(units_to_double(Pango\SCALE));

try {
    units_to_double(PHP_INT_MIN);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    units_to_double(PHP_INT_MAX);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    units_to_double();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    units_to_double(1, 2);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    units_to_double(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
float(1)
Pango\units_to_double(): Argument #1 ($units) must be a between -2147483648 and 2147483647
Pango\units_to_double(): Argument #1 ($units) must be a between -2147483648 and 2147483647
Pango\units_to_double() expects exactly 1 argument, 0 given
Pango\units_to_double() expects exactly 1 argument, 2 given
Pango\units_to_double(): Argument #1 ($units) must be of type int, array given
