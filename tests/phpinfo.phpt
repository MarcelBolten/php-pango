--TEST--
Pango extension phpinfo information
--SKIPIF--
<?php
include __DIR__ . '/skipif.php.inc';
?>
--FILE--
<?php
$ext = new ReflectionExtension('pango');
$ext->info();
?>
--EXPECTF--
pango

Pango text rendering support => enabled
Compiled as => dynamic module
against Pango version => %d.%d.%d
Currently loaded Pango version => %d.%d.%d
Extension version => 0.2.0-dev
Currently used Cairo version => %d.%d.%d
Currently used Fontconfig version => %d.%d.%d
Currently used HarfBuzz version => %d.%d.%d
Currently used FriBidi version => %d.%d.%d
Currently used FreeType version => %d.%d.%d
