--TEST--
Pango\Attribute\Attribute compare handler
--EXTENSIONS--
pango
--FILE--
<?php
$attribute1 = new Pango\Attribute\SizeAttribute(12);
var_dump($attribute1);
$attribute2 = new Pango\Attribute\SizeAttribute(13);
var_dump($attribute2);
var_dump($attribute1 == $attribute2);

$attribute3 = new Pango\Attribute\SizeAttribute(12);
var_dump($attribute3);
var_dump($attribute1 == $attribute3);

$attribute4 = new Pango\Attribute\StyleAttribute(Pango\Style::Italic);
var_dump($attribute4);
var_dump($attribute4 == $attribute1);
?>
--EXPECTF--
object(Pango\Attribute\SizeAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(12)
}
object(Pango\Attribute\SizeAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(13)
}
bool(false)
object(Pango\Attribute\SizeAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(12)
}
bool(true)
object(Pango\Attribute\StyleAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Style::Italic)
}
bool(false)
