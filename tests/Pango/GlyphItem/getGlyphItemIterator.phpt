--TEST--
Pango\GlyphItem::getGlyphItemIterator()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\GlyphItemIterInitLoc;
use Pango\Ft2\FontMap;
use Pango\Context;
use Pango\Layout;

var_dump(GlyphItemIterInitLoc::cases());

$fontMap = new FontMap();
var_dump($fontMap);
$context = new Context($fontMap);
var_dump($context);
$layout = new Layout($context);
var_dump($layout);

$layout->setText("Hello, Παν語!");
$runs = $layout->getLine(0)->getRuns();
$glyphItem = $runs[1];
$glyphItemIter = $glyphItem->getGlyphItemIterator();
var_dump($glyphItemIter);
$glyphItemIter = $glyphItem->getGlyphItemIterator(GlyphItemIterInitLoc::End);
var_dump($glyphItemIter);
$glyphItemIter = $glyphItem->getGlyphItemIterator(GlyphItemIterInitLoc::Beginning);
var_dump($glyphItemIter);
var_dump($glyphItemIter->prev());
while ($var = $glyphItemIter->next()) {
    var_dump($var);
    var_dump($glyphItemIter);
}
var_dump($var);
var_dump($glyphItemIter->prev());

var_dump($glyphItemIter->glyphItem);
var_dump($glyphItemIter->text);
var_dump($glyphItemIter->startByteIndex);
var_dump($glyphItemIter->startChar);
var_dump($glyphItemIter->startGlyph);
var_dump($glyphItemIter->endByteIndex);
var_dump($glyphItemIter->endChar);
var_dump($glyphItemIter->endGlyph);

try {
    $glyphItem->getGlyphItemIterator(GlyphItemIterInitLoc::Beginning, true);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $glyphItem->getGlyphItemIterator(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
array(2) {
  [0]=>
  enum(Pango\GlyphItemIterInitLoc::Beginning)
  [1]=>
  enum(Pango\GlyphItemIterInitLoc::End)
}
object(Pango\Ft2\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
object(Pango\GlyphItemIterator)#%d (8) {
  ["glyphItem"]=>
  object(Pango\GlyphItem)#%d (0) {
  }
  ["text"]=>
  string(17) "Hello, Παν語!"
  ["startGlyph"]=>
  int(0)
  ["startByteIndex"]=>
  int(7)
  ["startChar"]=>
  int(0)
  ["endGlyph"]=>
  int(1)
  ["endByteIndex"]=>
  int(9)
  ["endChar"]=>
  int(1)
}
object(Pango\GlyphItemIterator)#%d (8) {
  ["glyphItem"]=>
  object(Pango\GlyphItem)#%d (0) {
  }
  ["text"]=>
  string(17) "Hello, Παν語!"
  ["startGlyph"]=>
  int(2)
  ["startByteIndex"]=>
  int(11)
  ["startChar"]=>
  int(2)
  ["endGlyph"]=>
  int(3)
  ["endByteIndex"]=>
  int(13)
  ["endChar"]=>
  int(3)
}
object(Pango\GlyphItemIterator)#%d (8) {
  ["glyphItem"]=>
  object(Pango\GlyphItem)#%d (0) {
  }
  ["text"]=>
  string(17) "Hello, Παν語!"
  ["startGlyph"]=>
  int(0)
  ["startByteIndex"]=>
  int(7)
  ["startChar"]=>
  int(0)
  ["endGlyph"]=>
  int(1)
  ["endByteIndex"]=>
  int(9)
  ["endChar"]=>
  int(1)
}
bool(false)
bool(true)
object(Pango\GlyphItemIterator)#%d (8) {
  ["glyphItem"]=>
  object(Pango\GlyphItem)#%d (0) {
  }
  ["text"]=>
  string(17) "Hello, Παν語!"
  ["startGlyph"]=>
  int(1)
  ["startByteIndex"]=>
  int(9)
  ["startChar"]=>
  int(1)
  ["endGlyph"]=>
  int(2)
  ["endByteIndex"]=>
  int(11)
  ["endChar"]=>
  int(2)
}
bool(true)
object(Pango\GlyphItemIterator)#%d (8) {
  ["glyphItem"]=>
  object(Pango\GlyphItem)#%d (0) {
  }
  ["text"]=>
  string(17) "Hello, Παν語!"
  ["startGlyph"]=>
  int(2)
  ["startByteIndex"]=>
  int(11)
  ["startChar"]=>
  int(2)
  ["endGlyph"]=>
  int(3)
  ["endByteIndex"]=>
  int(13)
  ["endChar"]=>
  int(3)
}
bool(false)
bool(true)
object(Pango\GlyphItem)#%d (0) {
}
string(17) "Hello, Παν語!"
int(9)
int(1)
int(1)
int(11)
int(2)
int(2)
Pango\GlyphItem::getGlyphItemIterator() expects at most 1 argument, 2 given
Pango\GlyphItem::getGlyphItemIterator(): Argument #1 ($initialLocation) must be of type Pango\GlyphItemIterInitLoc, array given
