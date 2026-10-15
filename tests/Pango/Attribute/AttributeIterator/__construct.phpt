--TEST--
Pango\Attribute\AttributeIterator::__construct()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\AttributeIterator;

try {
    new AttributeIterator();
} catch (Error $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
Call to private Pango\Attribute\AttributeIterator::__construct() from global scope
