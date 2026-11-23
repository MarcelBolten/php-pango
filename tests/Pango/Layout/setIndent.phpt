--TEST--
Pango\Layout::setIndent()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Ft2\FontMap;

$fontMap = new FontMap();
$pathToFonts = dirname(__FILE__, 3) . "/assets/fonts";
$fontMap->addFontFile($pathToFonts . "/DejaVuSans.ttf");
$fontMap->addFontFile($pathToFonts . "/NotoSansJP-Regular.otf");
$fontMap->addFontFile($pathToFonts . "/NotoSans-Regular.ttf");
var_dump($fontMap);

$pangoContext = new Pango\Context($fontMap);
var_dump($pangoContext);

$layout = new Pango\Layout($pangoContext);
var_dump($layout);

var_dump($layout->getIndent());

$layout->setIndent(10 * Pango\SCALE);
var_dump($layout->getIndent());

$layout->setIndent(-10 * Pango\SCALE);
var_dump($layout->getIndent());

try {
    $layout->setIndent(1 << 31);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setIndent(-(1 << 31) - 1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setIndent();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setIndent(10, 'wrong');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setIndent(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Ft2\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
int(0)
int(10240)
int(-10240)
Pango\Layout::setIndent(): Argument #1 ($indent) must be greater than or equal to -2147483648 and less than or equal to 2147483647
Pango\Layout::setIndent(): Argument #1 ($indent) must be greater than or equal to -2147483648 and less than or equal to 2147483647
Pango\Layout::setIndent() expects exactly 1 argument, 0 given
Pango\Layout::setIndent() expects exactly 1 argument, 2 given
Pango\Layout::setIndent(): Argument #1 ($indent) must be of type int, array given
