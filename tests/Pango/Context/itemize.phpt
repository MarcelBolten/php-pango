--TEST--
Pango\Context::itemize()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AttributeList;
use Pango\Context;
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);
$context = new Context($fontMap);
var_dump($context);

$attrList = new AttributeList("0 7 size 16, 7 13 size 12, 13 16 size 14, 16 17 size 18");
$attrIter = $attrList->getIterator();

var_dump(count($context->itemize("Hello, Παν語!", 7, 0, $attrList)));
var_dump(count($context->itemize("Hello, Παν語!", 0, 17, $attrList)));
var_dump(count($context->itemize("Hello, Παν語!", 0, 17, $attrList, $attrIter)));
var_dump(count($context->itemize("Hello, Παν語!", 0, 17, $attrList, baseDir: Pango\Direction::RTL)));

try {
    $context->itemize("Hello,\0Παν語!", 0, 17, $attrList);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->itemize("Hello, Παν語!", -1, 17, $attrList);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->itemize("Hello, Παν語!", 99, 17, $attrList);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->itemize("Hello, Παν語!", 7, -1, $attrList);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->itemize("Hello, Παν語!", 7, 99, $attrList);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->itemize();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
int(0)
int(4)
int(4)
int(4)
Pango\Context::itemize(): Argument #1 ($text) must not contain NUL bytes
Pango\Context::itemize(): Argument #2 ($startByteIndex) must be between 0 and the byte length of text (17)
Pango\Context::itemize(): Argument #2 ($startByteIndex) must be between 0 and the byte length of text (17)
Pango\Context::itemize(): Argument #3 ($byteLength) must be between 0 and the byte length of text minus startByteIndex (10)
Pango\Context::itemize(): Argument #3 ($byteLength) must be between 0 and the byte length of text minus startByteIndex (10)
Pango\Context::itemize() expects at least 4 arguments, 0 given