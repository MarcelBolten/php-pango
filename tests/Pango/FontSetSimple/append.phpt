--TEST--
Pango\FontSetSimple::append()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Context;
use PangoCairo\FontMap;
use Pango\FontDescription;
use Pango\FontSetSimple;
use Pango\Language;

$fontMap = FontMap::getDefault();
var_dump($fontMap);
$context = new Context($fontMap);
var_dump($context);
$fontDesc = new FontDescription("Sans 12");
var_dump($fontDesc);
$font = $context->loadFont($fontDesc);
var_dump($font);

$fss = new FontSetSimple(new Language("en"));
var_dump($fss);
$fss->append($font);
var_dump($fss);

try {
    $fss->append();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fss->append($font, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fss->append(array());
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
object(Pango\FontSetSimple)#%d (1) {
  ["size"]=>
  int(0)
}
object(Pango\FontSetSimple)#%d (1) {
  ["size"]=>
  int(1)
}
Pango\FontSetSimple::append() expects exactly 1 argument, 0 given
Pango\FontSetSimple::append() expects exactly 1 argument, 2 given
Pango\FontSetSimple::append(): Argument #1 ($font) must be of type Pango\Font, array given
