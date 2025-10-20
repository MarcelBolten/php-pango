--TEST--
Pango\Context::listFamilies()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
use PangoCairo\FontMap;
use Pango\Context;

$fontMap = FontMap::getDefault();
var_dump($fontMap);

$context = new Context($fontMap);
var_dump($context);

$families = $context->listFamilies();
var_dump(is_array($families));
var_dump($families[0]);

try {
    $context->listFamilies(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
bool(true)
object(Pango\FontFamily)#%d (0) {
}
Pango\Context::listFamilies() expects exactly 0 arguments, 1 given
