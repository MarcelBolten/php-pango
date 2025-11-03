--TEST--
Pango\Context::setRoundGlyphPositions()
--EXTENSIONS--
pango
--FILE--
<?php
$context = new Pango\Context();
var_dump($context);
var_dump($context->getRoundGlyphPositions());

$context->setRoundGlyphPositions(false);
var_dump($context->getRoundGlyphPositions());

try {
    $context->setRoundGlyphPositions();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->setRoundGlyphPositions(true, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
try {
    $context->setRoundGlyphPositions(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Context)#%d (0) {
}
bool(true)
bool(false)
Pango\Context::setRoundGlyphPositions() expects exactly 1 argument, 0 given
Pango\Context::setRoundGlyphPositions() expects exactly 1 argument, 2 given
Pango\Context::setRoundGlyphPositions(): Argument #1 ($round) must be of type bool, array given
