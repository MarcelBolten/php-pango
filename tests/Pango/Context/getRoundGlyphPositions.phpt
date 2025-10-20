--TEST--
Pango\Context::getRoundGlyphPositions()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$context = new Pango\Context();
var_dump($context);
var_dump($context->getRoundGlyphPositions());

try {
    $context->getRoundGlyphPositions(array());
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Context)#%d (0) {
}
bool(true)
Pango\Context::getRoundGlyphPositions() expects exactly 0 arguments, 1 given
