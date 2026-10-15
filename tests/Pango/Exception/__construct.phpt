--TEST--
Pango\Exception new object
--EXTENSIONS--
pango
--FILE--
<?php
try {
    throw new Pango\Exception("test exception");
} catch (Pango\Exception $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
test exception
