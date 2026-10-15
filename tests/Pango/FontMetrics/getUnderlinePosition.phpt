--TEST--
Pango\FontMetrics::getUnderlinePosition()
--EXTENSIONS--
pango
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
var_dump($metrics->getUnderlinePosition());

try {
    $metrics->getUnderlinePosition(1);
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
int(%i)
Pango\FontMetrics::getUnderlinePosition() expects exactly 0 arguments, 1 given
