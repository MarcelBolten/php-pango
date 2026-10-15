--TEST--
Pango\Analysis new instance
--EXTENSIONS--
pango
--FILE--
<?php
$analysis = new Pango\Analysis();
var_dump($analysis);
?>
--EXPECTF--
object(Pango\Analysis)#1 (0) {
}
