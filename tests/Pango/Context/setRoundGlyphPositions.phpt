--TEST--
Pango\Context::setRoundGlyphPositions()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$layout = new Pango\Layout($cairoContext);
var_dump($layout);

$context = $layout->getContext();
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
object(Cairo\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
bool(true)
bool(false)
Pango\Context::setRoundGlyphPositions() expects exactly 1 argument, 0 given
Pango\Context::setRoundGlyphPositions() expects exactly 1 argument, 2 given
Pango\Context::setRoundGlyphPositions(): Argument #1 ($round) must be of type bool, array given
