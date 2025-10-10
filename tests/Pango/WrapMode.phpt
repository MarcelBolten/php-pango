--TEST--
Pango\WrapMode enum
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
?>
--FILE--
<?php
// case "None" is only available since 1.56.0
$cases = Pango\WrapMode::cases();
echo count($cases), "\n";

foreach ($cases as $case) {
    echo $case->name, "\n";
}
?>
--EXPECTREGEX--
(3|4)
Word
Char
WordChar
?(None)?
