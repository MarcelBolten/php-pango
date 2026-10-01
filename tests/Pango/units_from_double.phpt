--TEST--
Pango\units_from_double()
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
?>
--FILE--
<?php
use function Pango\units_from_double;

var_dump(units_from_double(1.001));

try {
    units_from_double();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    units_from_double(1, 2);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    units_from_double(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
int(1025)
Pango\units_from_double() expects exactly 1 argument, 0 given
Pango\units_from_double() expects exactly 1 argument, 2 given
Pango\units_from_double(): Argument #1 ($d) must be of type float, array given
