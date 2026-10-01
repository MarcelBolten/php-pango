--TEST--
Pango\Coverage clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Coverage;
use Pango\CoverageLevel;

$coverage = new Coverage();
var_dump($coverage);
$coverage->set(65, CoverageLevel::Exact);
var_dump($coverage->get(65));
$cov2 = clone $coverage;
var_dump($cov2);
var_dump($cov2->get(65));
?>
--EXPECT--
object(Pango\Coverage)#1 (0) {
}
enum(Pango\CoverageLevel::Exact)
object(Pango\Coverage)#3 (0) {
}
enum(Pango\CoverageLevel::Exact)
