--TEST--
Pango\LayoutIter::__construct()
--EXTENSIONS--
pango
--FILE--
<?php
try {
    var_dump(new Pango\LayoutIter());
} catch (Error $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
Call to private Pango\LayoutIter::__construct() from global scope
