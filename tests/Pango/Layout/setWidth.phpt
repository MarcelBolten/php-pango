--TEST--
Pango\Layout::setWidth()
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

var_dump($layout->getWidth());

$layout->setWidth(10 * Pango\SCALE);
var_dump($layout->getWidth());

$layout->setWidth(0);
var_dump($layout->getWidth());

$layout->setWidth(-1);
var_dump($layout->getWidth());

try {
    $layout->setWidth(1 << 31);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setWidth(-2);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setWidth();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setWidth(1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setWidth(array());
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
int(-1)
int(10240)
int(0)
int(-1)
Pango\Layout::setWidth(): Argument #1 ($width) must be less than or equal to 2147483647, or -1 to indicate no width
Pango\Layout::setWidth(): Argument #1 ($width) must be less than or equal to 2147483647, or -1 to indicate no width
Pango\Layout::setWidth() expects exactly 1 argument, 0 given
Pango\Layout::setWidth() expects exactly 1 argument, 2 given
Pango\Layout::setWidth(): Argument #1 ($width) must be of type int, array given
