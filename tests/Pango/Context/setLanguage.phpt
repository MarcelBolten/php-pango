--TEST--
Pango\Context::setLanguage()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$context = new Pango\Context();
var_dump($context);
var_dump($context->getLanguage());

$language = new Pango\Language('en');
var_dump($language);

$context->setLanguage($language);
$languageRetrieved = $context->getLanguage();
var_dump($languageRetrieved);

$context->setLanguage(null);
$languageRetrieved = $context->getLanguage();
var_dump($languageRetrieved);

try {
    $context->setLanguage();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->setLanguage(new Pango\Language('en'), 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->setLanguage(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Context)#%d (0) {
}
NULL
object(Pango\Language)#%d (1) {
  ["string-representation"]=>
  string(2) "en"
}
object(Pango\Language)#%d (1) {
  ["string-representation"]=>
  string(2) "en"
}
NULL
Pango\Context::setLanguage() expects exactly 1 argument, 0 given
Pango\Context::setLanguage() expects exactly 1 argument, 2 given
Pango\Context::setLanguage(): Argument #1 ($language) must be of type ?Pango\Language, array given
