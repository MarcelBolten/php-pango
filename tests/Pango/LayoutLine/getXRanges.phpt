--TEST--
Pango\LayoutLine::getXRanges()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);

$pangoContext = new Pango\Context($fontMap);
var_dump($pangoContext);

$layout = new Pango\Layout($pangoContext);
var_dump($layout);

$line = $layout->getLineReadonly(0);
var_dump($line->getXRanges());

$counts = array();
$text = "Hello,\nΠαν語!";
$layout->setText($text);
foreach ($layout->getLinesReadonly() as $id => $line) {
    $xRanges = $line->getXRanges();
    var_dump($xRanges);
    $counts[$id] = count($xRanges);
}

/*
 * Set a fixed width for the layout.
 * Now there should be 1 more xRange for each line,
 * because the last xRange ends at the end of the line,
 * which is not the end of the text
 */
$layout->setWidth(100_000);
$lenPlusOne = strlen($text) + 1;
foreach ($layout->getLinesReadonly() as $id => $line) {
    $xRanges = $line->getXRanges(byteEnd: $lenPlusOne);
    assert(count($xRanges) === $counts[$id] + 1);
}

try {
    $line->getXRanges(2, 1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $line->getXRanges(-1, 1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $line->getXRanges(2147483647 + 1, 1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $line->getXRanges(0, -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $line->getXRanges(0, 2147483647 + 1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $line->getXRanges(1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $line->getXRanges(array(), 2);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $line->getXRanges(1, array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
array(0) {
}
array(1) {
  [0]=>
  array(3) {
    ["start"]=>
    int(0)
    ["end"]=>
    int(%d)
    ["width"]=>
    int(%d)
  }
}
array(3) {
  [0]=>
  array(3) {
    ["start"]=>
    int(0)
    ["end"]=>
    int(%d)
    ["width"]=>
    int(%d)
  }
  [1]=>
  array(3) {
    ["start"]=>
    int(%d)
    ["end"]=>
    int(%d)
    ["width"]=>
    int(%d)
  }
  [2]=>
  array(3) {
    ["start"]=>
    int(%d)
    ["end"]=>
    int(%d)
    ["width"]=>
    int(%d)
  }
}
Pango\LayoutLine::getXRanges(): Argument #2 ($byteEnd) must be be greater than argument #1 ($byteStart) 2 but 1 given
Pango\LayoutLine::getXRanges(): Argument #1 ($byteStart) must be between 0 and 2147483647 but -1 given
Pango\LayoutLine::getXRanges(): Argument #1 ($byteStart) must be between 0 and 2147483647 but 2147483648 given
Pango\LayoutLine::getXRanges(): Argument #2 ($byteEnd) must be between 0 and 2147483647 but -1 given
Pango\LayoutLine::getXRanges(): Argument #2 ($byteEnd) must be between 0 and 2147483647 but 2147483648 given
Pango\LayoutLine::getXRanges() expects at most 2 arguments, 3 given
Pango\LayoutLine::getXRanges(): Argument #1 ($byteStart) must be of type ?int, array given
Pango\LayoutLine::getXRanges(): Argument #2 ($byteEnd) must be of type ?int, array given
