--TEST--
Pango\FontMap::listFamilies()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);

var_dump($fontMap->listFamilies());

try {
    $fontMap->listFamilies(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
array(23) {
  [0]=>
  string(16) "Noto Sans CJK SC"
  [1]=>
  string(16) "Noto Sans CJK KR"
  [2]=>
  string(16) "Noto Sans CJK HK"
  [3]=>
  string(16) "Noto Sans CJK JP"
  [4]=>
  string(16) "Noto Sans CJK TC"
  [5]=>
  string(21) "Noto Sans Mono CJK SC"
  [6]=>
  string(21) "Noto Sans Mono CJK TC"
  [7]=>
  string(21) "Noto Sans Mono CJK JP"
  [8]=>
  string(21) "Noto Sans Mono CJK KR"
  [9]=>
  string(21) "Noto Sans Mono CJK HK"
  [10]=>
  string(16) "DejaVu Sans Mono"
  [11]=>
  string(17) "Noto Serif CJK JP"
  [12]=>
  string(17) "Noto Serif CJK HK"
  [13]=>
  string(17) "Noto Serif CJK KR"
  [14]=>
  string(17) "Noto Serif CJK SC"
  [15]=>
  string(17) "Noto Serif CJK TC"
  [16]=>
  string(12) "DejaVu Serif"
  [17]=>
  string(11) "DejaVu Sans"
  [18]=>
  string(16) "Noto Color Emoji"
  [19]=>
  string(4) "Sans"
  [20]=>
  string(5) "Serif"
  [21]=>
  string(9) "Monospace"
  [22]=>
  string(9) "System-ui"
}
Pango\FontMap::listFamilies() expects exactly 0 arguments, 1 given
