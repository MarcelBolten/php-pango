--TEST--
Pango\Attribute\AttributeIterator::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
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
