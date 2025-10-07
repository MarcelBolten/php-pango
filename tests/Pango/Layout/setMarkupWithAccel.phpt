--TEST--
Pango\Layout::setMarkupWithAccel()
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

var_dump($layout->setMarkupWithAccel("<span foreground='blue' size='x-large'>_Hello,</span> <i>Παν語!</i>!", '_'));
var_dump($layout->getText());

var_dump($layout->setMarkupWithAccel("", ""));
var_dump($layout->getText());

//
// potential null byte in markup
//
// in text without markup, truncates at null byte
var_dump($layout->setMarkupWithAccel("_Null\0 0", "_"));
var_dump($layout->getText());

// in text, truncates at null byte
var_dump($layout->setMarkupWithAccel("<span foreground='blue'>_Null\0 1</span>", "_"));
var_dump($layout->getText());

// between tag and attribute, text is fine but markup parser fails
var_dump($layout->setMarkupWithAccel("<span\0 foreground='blue'>_Null 2</span>", "_"));
var_dump($layout->getText());

// in attribute name, emits pango warning, fails to set text
var_dump($layout->setMarkupWithAccel("<span fore\0ground='blue'>_Null 3</span>", "_"));
var_dump($layout->getText());

// in attribute value, emits pango warning, fails to set text
var_dump($layout->setMarkupWithAccel("<span foreground='bl\0ue'>_Null 4</span>", "_"));
var_dump($layout->getText());

// in open tag name, emits pango warning, fails to set text
var_dump($layout->setMarkupWithAccel("<sp\0an foreground='blue'>_Null 5</span>", "_"));
var_dump($layout->getText());

// in closing tag name, emits pango warning, fails to set text
var_dump($layout->setMarkupWithAccel("<span foreground='blue'>_Null 5</sp\0an>", "_"));
var_dump($layout->getText());

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
object(Cairo\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
string(1) "H"
string(18) "Hello, Παν語!!"
string(0) ""
string(0) ""

Notice: Pango\Pango::setMarkupWithAccel(): Markup contains null byte. This may cause the underlying pango markup parser to fail, the text may be truncated, or not be set. %s
string(1) "N"
string(4) "Null"

Notice: Pango\Pango::setMarkupWithAccel(): Markup contains null byte. This may cause the underlying pango markup parser to fail, the text may be truncated, or not be set. %s
string(1) "N"
string(4) "Null"

Notice: Pango\Pango::setMarkupWithAccel(): Markup contains null byte. This may cause the underlying pango markup parser to fail, the text may be truncated, or not be set. %s
string(1) "N"
string(6) "Null 2"

Notice: Pango\Pango::setMarkupWithAccel(): Markup contains null byte. This may cause the underlying pango markup parser to fail, the text may be truncated, or not be set. %s

(process:%d): Pango-WARNING **: %s: pango_layout_set_markup_with_accel: Attribute 'fore' is not allowed on the <span> tag on line 1 char 34
string(0) ""
string(6) "Null 2"

Notice: Pango\Pango::setMarkupWithAccel(): Markup contains null byte. This may cause the underlying pango markup parser to fail, the text may be truncated, or not be set. %s

(process:%d): Pango-WARNING **: %s: pango_layout_set_markup_with_accel: Value of 'foreground' attribute on <span> tag on line 1 could not be parsed; should be a color specification, not 'bl'
string(0) ""
string(6) "Null 2"

Notice: Pango\Pango::setMarkupWithAccel(): Markup contains null byte. This may cause the underlying pango markup parser to fail, the text may be truncated, or not be set. %s

(process:%d): Pango-WARNING **: %s: pango_layout_set_markup_with_accel: Unknown tag 'sp' on line 1 char 34
string(0) ""
string(6) "Null 2"

Notice: Pango\Pango::setMarkupWithAccel(): Markup contains null byte. This may cause the underlying pango markup parser to fail, the text may be truncated, or not be set. %s

(process:%d): Pango-WARNING **: %s pango_layout_set_markup_with_accel: Error on line 1 char 47: Element “sp” was closed, but the currently open element is “span”
string(0) ""
string(6) "Null 2"
Pango\Layout::setMarkupWithAccel() expects exactly 2 arguments, 0 given
Pango\Layout::setMarkupWithAccel() expects exactly 2 arguments, 3 given
Pango\Layout::setMarkupWithAccel(): Argument #1 ($markup) must be of type string, array given
Pango\Layout::setMarkupWithAccel(): Argument #2 ($accelMarker) must be of type string, array given