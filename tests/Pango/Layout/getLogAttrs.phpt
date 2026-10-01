--TEST--
Pango\Layout::getLogAttrs()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);

$pangoContext = new Pango\Context($fontMap);
var_dump($pangoContext);

$layout = new Pango\Layout($pangoContext);
var_dump($layout);

var_dump($layout->getLogAttrs()->getAttributes());

$layout->setText("Hello, Παν語!");

var_dump(count($layout->getLogAttrs()));

try {
    $layout->getLogAttrs('wrong');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
array(1) {
  [0]=>
  object(Pango\LogAttr)#%d (15) {
    ["lineBreak"]=>
    bool(true)
    ["mandatoryBreak"]=>
    bool(true)
    ["charBreak"]=>
    bool(true)
    ["white"]=>
    bool(true)
    ["cursorPosition"]=>
    bool(true)
    ["wordStart"]=>
    bool(false)
    ["wordEnd"]=>
    bool(false)
    ["sentenceBoundary"]=>
    bool(true)
    ["sentenceStart"]=>
    bool(false)
    ["sentenceEnd"]=>
    bool(false)
    ["backspaceDeletesCharacter"]=>
    bool(true)
    ["expandableSpace"]=>
    bool(false)
    ["wordBoundary"]=>
    bool(true)
    ["breakInsertsHyphen"]=>
    bool(false)
    ["breakRemovesPreceding"]=>
    bool(false)
  }
}
int(13)
Pango\Layout::getLogAttrs() expects exactly 0 arguments, 1 given
