--TEST--
Pango\Layout::setMarkup()
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

$layout->setMarkup("<span foreground='blue' size='x-large'>Hello,</span> <i>Παν語!</i>!");
var_dump($layout->getText());

$layout->setMarkup("");
var_dump($layout->getText());

//
// potential NUL byte in markup
//
// in text without markup, truncates at NUL byte
try {
    $layout->setMarkup("Null\0 0");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

// in text, truncates at NUL byte
try {
    $layout->setMarkup("<span foreground='blue'>Null\0 1</span>");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

// between tag and attribute, text is fine but markup parser fails
try {
    $layout->setMarkup("<span\0 foreground='blue'>Null 2</span>");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

// in attribute name, emits pango warning, fails to set text
try {
    $layout->setMarkup("<span fore\0ground='blue'>Null 3</span>");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

// in attribute value, emits pango warning, fails to set text
try {
    $layout->setMarkup("<span foreground='bl\0ue'>Null 4</span>");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

// in open tag name, emits pango warning, fails to set text
try {
    $layout->setMarkup("<sp\0an foreground='blue'>Null 5</span>");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

// in closing tag name, emits pango warning, fails to set text
try {
    $layout->setMarkup("<span foreground='blue'>Null 5</sp\0an>");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setMarkup();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setMarkup("<b>Hello</b>", "<i>Παν語!</i>");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setMarkup(array());
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
string(18) "Hello, Παν語!!"
string(0) ""
Pango\Layout::setMarkup(): Argument #1 ($markup) must not contain NUL bytes
Pango\Layout::setMarkup(): Argument #1 ($markup) must not contain NUL bytes
Pango\Layout::setMarkup(): Argument #1 ($markup) must not contain NUL bytes
Pango\Layout::setMarkup(): Argument #1 ($markup) must not contain NUL bytes
Pango\Layout::setMarkup(): Argument #1 ($markup) must not contain NUL bytes
Pango\Layout::setMarkup(): Argument #1 ($markup) must not contain NUL bytes
Pango\Layout::setMarkup(): Argument #1 ($markup) must not contain NUL bytes
Pango\Layout::setMarkup() expects exactly 1 argument, 0 given
Pango\Layout::setMarkup() expects exactly 1 argument, 2 given
Pango\Layout::setMarkup(): Argument #1 ($markup) must be of type string, array given
