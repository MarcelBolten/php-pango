--TEST--
Pango\Context::__construct()
--EXTENSIONS--
pango
cairo
--FILE--
<?php
use Pango\Context;
use PangoCairo\FontMap;

$pangoContext = new Context();
var_dump($pangoContext);

$fontMap = FontMap::getDefault();
var_dump($fontMap);
$pangoContextFromFontMap = new Context($fontMap);
var_dump($pangoContextFromFontMap);

try {
    new Context($fontMap, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Context(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Context)#%d (0) {
}
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
Pango\Context::__construct() expects at most 1 argument, 2 given
Pango\Context::__construct(): Argument #1 ($fontmap) must be of type ?Pango\FontMap, array given
