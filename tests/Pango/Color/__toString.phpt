--TEST--
Pango\Color::__toString
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Color;

$color = new Color(0xFFFF, 0x1111, 0x8888);
var_dump($color->__toString());
echo $color, "\n";
?>
--EXPECTF--
string(13) "#ffff11118888"
#ffff11118888
