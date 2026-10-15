--TEST--
Pango\Context::getFontDescription()
--EXTENSIONS--
pango
--FILE--
<?php
$context = new Pango\Context();
var_dump($context);
var_dump($context->getFontDescription());

try {
    $context->getFontDescription(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Context)#%d (0) {
}
NULL
Pango\Context::getFontDescription() expects exactly 0 arguments, 1 given
