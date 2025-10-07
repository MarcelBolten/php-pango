--TEST--
Pango\Layout::setMarkup()
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

$layout->setMarkup("<span foreground='blue' size='x-large'>Hello,</span> <i>Παν語!</i>!");
var_dump($layout->getText());

$layout->setMarkup("");
var_dump($layout->getText());

//
// potential null byte in markup
//
// in text without markup, truncates at null byte
$layout->setMarkup("Null\0 0");
var_dump($layout->getText());

// in text, truncates at null byte
$layout->setMarkup("<span foreground='blue'>Null\0 1</span>");
var_dump($layout->getText());

// between tag and attribute, text is fine but markup parser fails
$layout->setMarkup("<span\0 foreground='blue'>Null 2</span>");
var_dump($layout->getText());

// in attribute name, emits pango warning, fails to set text
$layout->setMarkup("<span fore\0ground='blue'>Null 3</span>");
var_dump($layout->getText());

// in attribute value, emits pango warning, fails to set text
$layout->setMarkup("<span foreground='bl\0ue'>Null 4</span>");
var_dump($layout->getText());

// in open tag name, emits pango warning, fails to set text
$layout->setMarkup("<sp\0an foreground='blue'>Null 5</span>");
var_dump($layout->getText());

// in closing tag name, emits pango warning, fails to set text
$layout->setMarkup("<span foreground='blue'>Null 5</sp\0an>");
var_dump($layout->getText());

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
object(Cairo\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
string(18) "Hello, Παν語!!"
string(0) ""

Notice: Pango\Pango::setMarkup(): Markup contains null byte. This may cause the underlying pango markup parser to fail, the text may be truncated, or not be set. %s
string(4) "Null"

Notice: Pango\Pango::setMarkup(): Markup contains null byte. This may cause the underlying pango markup parser to fail, the text may be truncated, or not be set. %s
string(4) "Null"

Notice: Pango\Pango::setMarkup(): Markup contains null byte. This may cause the underlying pango markup parser to fail, the text may be truncated, or not be set. %s
string(6) "Null 2"

Notice: Pango\Pango::setMarkup(): Markup contains null byte. This may cause the underlying pango markup parser to fail, the text may be truncated, or not be set. %s

(process:%d): Pango-WARNING **: %s: pango_layout_set_markup_with_accel: Attribute 'fore' is not allowed on the <span> tag on line 1 char 34
string(6) "Null 2"

Notice: Pango\Pango::setMarkup(): Markup contains null byte. This may cause the underlying pango markup parser to fail, the text may be truncated, or not be set. %s

(process:%d): Pango-WARNING **: %s: pango_layout_set_markup_with_accel: Value of 'foreground' attribute on <span> tag on line 1 could not be parsed; should be a color specification, not 'bl'
string(6) "Null 2"

Notice: Pango\Pango::setMarkup(): Markup contains null byte. This may cause the underlying pango markup parser to fail, the text may be truncated, or not be set. %s

(process:%d): Pango-WARNING **: %s: pango_layout_set_markup_with_accel: Unknown tag 'sp' on line 1 char 34
string(6) "Null 2"

Notice: Pango\Pango::setMarkup(): Markup contains null byte. This may cause the underlying pango markup parser to fail, the text may be truncated, or not be set. %s

(process:%d): Pango-WARNING **: %s pango_layout_set_markup_with_accel: Error on line 1 char 46: Element “sp” was closed, but the currently open element is “span”
string(6) "Null 2"
Pango\Layout::setMarkup() expects exactly 1 argument, 0 given
Pango\Layout::setMarkup() expects exactly 1 argument, 2 given
Pango\Layout::setMarkup(): Argument #1 ($markup) must be of type string, array given
