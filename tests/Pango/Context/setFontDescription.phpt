--TEST--
Pango\Context::setFontDescription()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$context = new Pango\Context();
var_dump($context);
var_dump($context->getFontDescription());

$fontDescription = new Pango\FontDescription('Serif 12');
var_dump($fontDescription);

$context->setFontDescription($fontDescription);
$fontDescriptionRetrieved = $context->getFontDescription();
var_dump($fontDescriptionRetrieved);
var_dump($fontDescription === $fontDescriptionRetrieved);

try {
    $context->setFontDescription();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->setFontDescription(new Pango\FontDescription('Serif 12'), 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->setFontDescription(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Context)#%d (0) {
}
NULL
object(Pango\FontDescription)#%d (0) {
}
object(Pango\FontDescription)#%d (0) {
}
bool(true)
Pango\Context::setFontDescription() expects exactly 1 argument, 0 given
Pango\Context::setFontDescription() expects exactly 1 argument, 2 given
Pango\Context::setFontDescription(): Argument #1 ($desc) must be of type Pango\FontDescription, array given
