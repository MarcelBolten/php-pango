--TEST--
Pango\Context::setFontDescription()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$context = new Pango\Context();
var_dump($context);
var_dump($context->getFontDescription());

$fontDescription = new Pango\FontDescription('Serif 12');
var_dump($fontDescription);

$context->setFontDescription($fontDescription);
$fontDescriptionRetrieved = $context->getFontDescription();
var_dump($fontDescriptionRetrieved);
var_dump($fontDescription === $fontDescriptionRetrieved);

// Note: Pango is inconsistent here: The docs say that NULL is allowed, but the implementation asserts is not NULL.
// https://gitlab.gnome.org/GNOME/pango/-/blob/0f27f82b162c3d03dea064fad63004ec9cf876b4/pango/pango-context.c#L339-350
// TODO: follow up with Pango maintainers https://gitlab.gnome.org/GNOME/pango/-/issues/876
$context->setFontDescription(null);
var_dump($context->getFontDescription());

try {
    $context->setFontDescription();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->setFontDescription(new Pango\FontDescription('Serif 12'), 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->setFontDescription(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Context)#%d (0) {
}
NULL
object(Pango\FontDescription)#%d (0) {
}
object(Pango\FontDescription)#%d (0) {
}
bool(true)

(process:%d): Pango-CRITICAL **: %s: pango_context_set_font_description: assertion 'desc != NULL' failed
NULL
Pango\Context::setFontDescription() expects exactly 1 argument, 0 given
Pango\Context::setFontDescription() expects exactly 1 argument, 2 given
Pango\Context::setFontDescription(): Argument #1 ($desc) must be of type ?Pango\FontDescription, array given
