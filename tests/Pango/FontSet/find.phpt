--TEST--
Pango\FontSet::find()
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
$language = new Language("en");
var_dump($language);
$fontSet = $context->loadFontSet($fontDesc, $language);
var_dump($fontSet);

var_dump($fontSet->find(fn (Pango\Font $font): bool => $font->hasChar('A')));
var_dump($fontSet->find(fn (Pango\Font $font): bool => $font->hasChar('あ')));
var_dump($fontSet->find(fn (Pango\Font $font): bool => $font->hasChar("\1")));

// callback must return a boolean value
try {
    $fontSet->find(fn (Pango\Font $font): int => 1);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

// throwing an exception in the callback will propagate the exception to the caller and leave the original list unchanged
try {
    $fontSet->find(fn (Pango\Font $font): bool => throw new Exception("exception in callback"));
} catch (Exception $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontSet->find();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontSet->find(0, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontSet->find(0);
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
object(Pango\Language)#%d (1) {
  ["string-representation"]=>
  string(2) "en"
}
object(Pango\FontSet)#%d (0) {
}
object(Pango\Font)#%d (1) {
  ["string-representation"]=>
  string(14) "DejaVu Sans 12"
}
object(Pango\Font)#%d (1) {
  ["string-representation"]=>
  string(19) "Noto Sans CJK JP 12"
}
NULL
Pango\FontSet::find(): Argument #1 ($callback) must return a boolean value
exception in callback
Pango\FontSet::find() expects exactly 1 argument, 0 given
Pango\FontSet::find() expects exactly 1 argument, 2 given
Pango\FontSet::find(): Argument #1 ($callback) must be a valid callback, no array or string given
