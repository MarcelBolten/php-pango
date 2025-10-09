--TEST--
Pango\WrapMode enum
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
?>
--FILE--
<?php
// None case only available since 1.56.0
$cases = Pango\WrapMode::cases();
echo count($cases), "\n";

foreach ($cases as $case) {
    echo $case->name, "\n";
}
?>
--EXPECTF--
%d
Word
Char
WordChar
%a
