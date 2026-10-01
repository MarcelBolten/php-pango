--TEST--
Pango\Context::getMetrics()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Context;
use PangoCairo\FontMap;
use Pango\FontDescription;
use Pango\Language;

$fontMap = FontMap::getDefault();
var_dump($fontMap);
$context = new Context($fontMap);
var_dump($context);
var_dump($context->getMetrics());

var_dump($context->getMetrics(desc: new FontDescription()));
var_dump($context->getMetrics(language: new Language('ja')));

try {
    $context->getMetrics(new FontDescription(), new Language('en'), 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->getMetrics(array(), new Language('en'));
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->getMetrics(new FontDescription(), array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\FontMetrics)#%d (0) {
}
object(Pango\FontMetrics)#%d (0) {
}
object(Pango\FontMetrics)#%d (0) {
}
Pango\Context::getMetrics() expects at most 2 arguments, 3 given
Pango\Context::getMetrics(): Argument #1 ($desc) must be of type ?Pango\FontDescription, array given
Pango\Context::getMetrics(): Argument #2 ($language) must be of type ?Pango\Language, array given
