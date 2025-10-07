--TEST--
Pango\Item read property handler
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

$layout->setText("Hello, Παν語!");
foreach ($layout->getLinesReadonly() as $line) {
    foreach(get_object_vars($line->getRuns()[1]->item) as $name => $value) {
        echo $name, ": ", get_debug_type($value);
        if (gettype($value) !== 'object') {
            echo "($value)";
        }
        echo "\n";
    }
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
offset: int(7)
length: int(6)
numChars: int(3)
