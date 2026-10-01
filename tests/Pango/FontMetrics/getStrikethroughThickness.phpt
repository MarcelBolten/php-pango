--TEST--
Pango\FontMetrics::getStrikethroughThickness()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Context;
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);
$context = new Context($fontMap);
var_dump($context);
$metrics = $context->getMetrics();
var_dump($metrics);
var_dump($metrics->getStrikethroughThickness());

try {
    $metrics->getStrikethroughThickness(1);
} catch (ArgumentCountError $e) {
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
int(%d)
Pango\FontMetrics::getStrikethroughThickness() expects exactly 0 arguments, 1 given
