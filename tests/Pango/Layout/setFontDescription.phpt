--TEST--
Pango\Layout::setFontDescription()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$layout = new Pango\Layout($cairoContext);
var_dump($layout);

var_dump($layout->getFontDescription());

$fontDescription = new Pango\FontDescription("serif");
$layout->setFontDescription($fontDescription);

$fontDescription = $layout->getFontDescription();
var_dump($fontDescription);
var_dump($fontDescription->getFamily());

try {
    $layout->setFontDescription();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setFontDescription($fontDescription, 'wrong');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setFontDescription(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
NULL
object(Pango\FontDescription)#%d (0) {
}
string(5) "serif"
Pango\Layout::setFontDescription() expects exactly 1 argument, 0 given
Pango\Layout::setFontDescription() expects exactly 1 argument, 2 given
Pango\Layout::setFontDescription(): Argument #1 ($desc) must be of type Pango\FontDescription, array given
