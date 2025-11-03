--TEST--
Pango extension phpinfo information
--EXTENSIONS--
pango
--FILE--
<?php
$ext = new ReflectionExtension('pango');
$ext->info();
?>
--EXPECTF--
pango

Pango text rendering support => enabled
Compiled as => dynamic module
Pango version => %d.%d.%d
Extension version => %s
