--TEST--
Pango\Attribute\GravityHint object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\GravityHint;

$gravityHint = new GravityHint(Pango\GravityHint::Strong);
$gravityHint->value = Pango\GravityHint::Line;
$gravityHint->startIndex = 13;
$gravityHint->endIndex = 42;

var_dump($gravityHint->value);
var_dump($gravityHint->startIndex);
var_dump($gravityHint->endIndex);

try {
    $gravityHint->value = 0;
}
catch (Throwable $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
enum(Pango\GravityHint::Line)
int(13)
int(42)
Cannot assign int to property Pango\Attribute\GravityHint::$value of type Pango\GravityHint
