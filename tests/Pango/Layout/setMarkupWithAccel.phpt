--TEST--
Pango\Layout::setMarkupWithAccel()
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
var_dump($layout->getAccelChar());

var_dump($layout
    ->setMarkupWithAccel("<span foreground='blue' size='x-large'>_Hello,</span> <i>Παν語</i>!", '_')
    ->getAccelChar()
);
var_dump($layout->getText());

var_dump($layout->setMarkupWithAccel("", "")->getAccelChar());
var_dump($layout->getText());

//
// potential NUL byte in markup
//
// in text without markup, truncates at NUL byte
try {
    var_dump($layout->setMarkupWithAccel("_Null\0 0", "_"));
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

// in text, truncates at NUL byte
try {
    var_dump($layout->setMarkupWithAccel("<span foreground='blue'>_Null\0 1</span>", "_"));
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

// between tag and attribute, text is fine but markup parser fails
try {
    var_dump($layout->setMarkupWithAccel("<span\0 foreground='blue'>_Null 2</span>", "_"));
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

// in attribute name, emits pango warning, fails to set text
try {
    var_dump($layout->setMarkupWithAccel("<span fore\0ground='blue'>_Null 3</span>", "_"));
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

// in attribute value, emits pango warning, fails to set text
try {
    var_dump($layout->setMarkupWithAccel("<span foreground='bl\0ue'>_Null 4</span>", "_"));
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

// in open tag name, emits pango warning, fails to set text
try {
    var_dump($layout->setMarkupWithAccel("<sp\0an foreground='blue'>_Null 5</span>", "_"));
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

// in closing tag name, emits pango warning, fails to set text
try {
    var_dump($layout->setMarkupWithAccel("<span foreground='blue'>_Null 5</sp\0an>", "_"));
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setMarkupWithAccel();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setMarkupWithAccel("<b>_Hello</b>", "_","<i>Παν語!</i>");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setMarkupWithAccel(array(), "_");
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setMarkupWithAccel("_Hello", array());
} catch (TypeError $e) {
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
string(0) ""
string(1) "H"
string(17) "Hello, Παν語!"
string(0) ""
string(0) ""
Pango\Layout::setMarkupWithAccel(): Argument #1 ($markup) must not contain NUL bytes
Pango\Layout::setMarkupWithAccel(): Argument #1 ($markup) must not contain NUL bytes
Pango\Layout::setMarkupWithAccel(): Argument #1 ($markup) must not contain NUL bytes
Pango\Layout::setMarkupWithAccel(): Argument #1 ($markup) must not contain NUL bytes
Pango\Layout::setMarkupWithAccel(): Argument #1 ($markup) must not contain NUL bytes
Pango\Layout::setMarkupWithAccel(): Argument #1 ($markup) must not contain NUL bytes
Pango\Layout::setMarkupWithAccel(): Argument #1 ($markup) must not contain NUL bytes
Pango\Layout::setMarkupWithAccel() expects exactly 2 arguments, 0 given
Pango\Layout::setMarkupWithAccel() expects exactly 2 arguments, 3 given
Pango\Layout::setMarkupWithAccel(): Argument #1 ($markup) must be of type string, array given
Pango\Layout::setMarkupWithAccel(): Argument #2 ($accelMarker) must be of type string, array given