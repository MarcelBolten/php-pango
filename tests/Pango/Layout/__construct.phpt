--TEST--
Pango\Layout::__construct()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Ft2\FontMap;
use Pango\Layout;

$fontMap = new FontMap();
$pathToFonts = dirname(__FILE__, 3) . "/assets/fonts";
$fontMap->addFontFile($pathToFonts . "/DejaVuSans.ttf");
$fontMap->addFontFile($pathToFonts . "/NotoSansJP-Regular.otf");
$fontMap->addFontFile($pathToFonts . "/NotoSans-Regular.ttf");
var_dump($fontMap);

$pangoContext = $fontMap->createContext();
var_dump($pangoContext);

$layout = new Layout($pangoContext);
var_dump($layout);

try {
    new Layout();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Layout(1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new Layout(array());
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
Pango\Layout::__construct() expects exactly 1 argument, 0 given
Pango\Layout::__construct() expects exactly 1 argument, 2 given
Pango\Layout::__construct(): Argument #1 ($context) must be of type Pango\Context, array given
