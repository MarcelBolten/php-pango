--TEST--
pango extension phpinfo information
--SKIPIF--
<?php
include __DIR__ . '/skipif.php.inc';
--FILE--
<?php
$ext = new ReflectionExtension('pango');
$ext->info();
--EXPECTF--
pango

Pango text rendering support => enabled
Compiled as => dynamic module
Pango version => %d.%d.%d
Extension version => %s