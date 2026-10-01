--TEST--
Pango\Language::includesScript()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Language;

$language = new Language("en-US");
var_dump($language->includesScript(Pango\Script::Latin));

$language = new Language("ja");
var_dump($language->includesScript(Pango\Script::Hiragana));

try {
    $language->includesScript();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $language->includesScript(Pango\Script::Latin, "extra");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $language->includesScript(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
bool(true)
bool(true)
Pango\Language::includesScript() expects exactly 1 argument, 0 given
Pango\Language::includesScript() expects exactly 1 argument, 2 given
Pango\Language::includesScript(): Argument #1 ($script) must be of type Pango\Script, array given
