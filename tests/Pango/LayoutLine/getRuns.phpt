--TEST--
Pango\LayoutLine::getRuns()
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

$line = $layout->getLineReadonly(0);
var_dump($line->getRuns());

$layout->setText("Hello, Παν語!");
foreach ($layout->getLinesReadonly() as $line) {
    var_dump($line instanceof Pango\LayoutLine);
    foreach ($line->getRuns() as $run) {
      var_dump($run instanceof Pango\GlyphItem);
    }
}

try {
    $line->getRuns(1);
} catch (ArgumentCountError $e) {
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
array(0) {
}
bool(true)
bool(true)
bool(true)
bool(true)
bool(true)
Pango\LayoutLine::getRuns() expects exactly 0 arguments, 1 given
