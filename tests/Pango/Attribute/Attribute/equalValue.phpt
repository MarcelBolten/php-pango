--TEST--
Pango\Attribute\Attribute::equalValue()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
$attribute1 = new Pango\Attribute\Size(12);
var_dump($attribute1);
$attribute2 = new Pango\Attribute\Size(13);
var_dump($attribute2);
var_dump($attribute1->equalValue($attribute2));

$attribute3 = new Pango\Attribute\Size(12);
var_dump($attribute3);
var_dump($attribute1->equalValue($attribute3));

$attribute4 = new Pango\Attribute\Style(Pango\Style::Italic);
var_dump($attribute4);
var_dump($attribute4->equalValue($attribute1));

$attribute4 = new Pango\Attribute\Size(12, 10, 20);
var_dump($attribute4);
var_dump($attribute4->equalValue($attribute1));
?>
--EXPECTF--
object(Pango\Attribute\Size)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(12)
}
object(Pango\Attribute\Size)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(13)
}
bool(false)
object(Pango\Attribute\Size)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(12)
}
bool(true)
object(Pango\Attribute\Style)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Style::Italic)
}
bool(false)
object(Pango\Attribute\Size)#%d (3) {
  ["startIndex"]=>
  int(10)
  ["endIndex"]=>
  int(20)
  ["value"]=>
  int(12)
}
bool(true)
