--TEST--
Pango\Layout::setWrap()
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

var_dump($layout->getWrap());

$layout->setWrap(Pango\WrapMode::Char);
var_dump($layout->getWrap());

try {
    $layout->setWrap();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setWrap(Pango\WrapMode::Word, 'wrong');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setWrap('left');
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
enum(Pango\WrapMode::Word)
enum(Pango\WrapMode::Char)
Pango\Layout::setWrap() expects exactly 1 argument, 0 given
Pango\Layout::setWrap() expects exactly 1 argument, 2 given
Pango\Layout::setWrap(): Argument #1 ($wrap) must be of type Pango\WrapMode, string given
