--TEST--
Pango\Font::getCoverage()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Context;
use PangoCairo\FontMap;
use Pango\FontDescription;
use Pango\Language;

$fontMap = FontMap::getDefault();
var_dump($fontMap);
$context = new Context($fontMap);
var_dump($context);
$fontDesc = new FontDescription("Sans 12");
var_dump($fontDesc);
$font = $context->loadFont($fontDesc);
var_dump($font);
$lang = new Language("en");
$coverage = $font->getCoverage($lang);
var_dump($coverage);
var_dump($coverage->get(ord('A')));
var_dump($coverage->get(mb_ord('あ')));

try {
    $font->getCoverage();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $font->getCoverage($lang, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $font->getCoverage(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\FontDescription)#%d (0) {
}
object(Pango\Font)#%d (1) {
  ["string-representation"]=>
  string(14) "DejaVu Sans 12"
}
object(Pango\Coverage)#%d (0) {
}
enum(Pango\CoverageLevel::Exact)
enum(Pango\CoverageLevel::None)
Pango\Font::getCoverage() expects exactly 1 argument, 0 given
Pango\Font::getCoverage() expects exactly 1 argument, 2 given
Pango\Font::getCoverage(): Argument #1 ($language) must be of type Pango\Language, array given
