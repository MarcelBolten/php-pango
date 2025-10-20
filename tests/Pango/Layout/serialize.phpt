--TEST--
Pango\Layout::serialize()
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

$layout->setText('Hello, Παν語!');
var_dump($layout->serialize());

var_dump($layout->serialize(
    Pango\Layout::SERIALIZE_CONTEXT
    | Pango\Layout::SERIALIZE_OUTPUT
));

try {
    $layout->serialize(1, 2);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->serialize(array());
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
string(35) "{
  "text" : "Hello, Παν語!"
}
"
string(7655) "{
  "context" : {
    "font" : "serif 12",
    "base-gravity" : "south",
    "gravity-hint" : "natural",
    "base-dir" : "weak-ltr",
    "round-glyph-positions" : true,
    "transform" : [
      1,
      0,
      0,
      1,
      0,
      0
    ]
  },
  "text" : "Hello, Παν語!",
  "output" : {
    "is-wrapped" : false,
    "is-ellipsized" : false,
    "unknown-glyphs" : 0,
    "width" : 112640,
    "height" : 24576,
    "log-attrs" : [
      {
        "char-break" : true,
        "cursor-position" : true,
        "word-start" : true,
        "sentence-boundary" : true,
        "sentence-start" : true,
        "backspace-deletes-character" : true,
        "word-boundary" : true
      },
      {
        "char-break" : true,
        "cursor-position" : true,
        "break-inserts-hyphen" : true
      },
      {
        "char-break" : true,
        "cursor-position" : true,
        "break-inserts-hyphen" : true
      },
      {
        "char-break" : true,
        "cursor-position" : true,
        "break-inserts-hyphen" : true
      },
      {
        "char-break" : true,
        "cursor-position" : true,
        "break-inserts-hyphen" : true
      },
      {
        "char-break" : true,
        "cursor-position" : true,
        "word-end" : true,
        "word-boundary" : true
      },
      {
        "char-break" : true,
        "white" : true,
        "cursor-position" : true,
        "expandable-space" : true,
        "word-boundary" : true
      },
      {
        "line-break" : true,
        "char-break" : true,
        "cursor-position" : true,
        "word-start" : true,
        "word-boundary" : true
      },
      {
        "char-break" : true,
        "cursor-position" : true,
        "break-inserts-hyphen" : true
      },
      {
        "char-break" : true,
        "cursor-position" : true,
        "break-inserts-hyphen" : true
      },
      {
        "line-break" : true,
        "char-break" : true,
        "cursor-position" : true,
        "word-boundary" : true
      },
      {
        "char-break" : true,
        "cursor-position" : true,
        "word-end" : true,
        "backspace-deletes-character" : true,
        "word-boundary" : true
      },
      {
        "line-break" : true,
        "mandatory-break" : true,
        "char-break" : true,
        "white" : true,
        "cursor-position" : true,
        "sentence-boundary" : true,
        "sentence-end" : true,
        "word-boundary" : true
      }
    ],
    "lines" : [
      {
        "start-index" : 0,
        "length" : 17,
        "paragraph-start" : true,
        "direction" : "ltr",
        "runs" : [
          {
            "offset" : 0,
            "length" : 7,
            "text" : "Hello, ",
            "bidi-level" : 0,
            "gravity" : "south",
            "language" : "c",
            "script" : "latin",
            "font" : {
              "description" : "DejaVu Serif 12",
              "checksum" : "%s",
              "matrix" : [
                1,
                -0,
                -0,
                1,
                0,
                0
              ]
            },
            "flags" : 0,
            "y-offset" : 0,
            "start-x-offset" : 0,
            "end-x-offset" : 0,
            "glyphs" : [
              {
                "glyph" : 43,
                "width" : 14336,
                "is-cluster-start" : true,
                "log-cluster" : 0
              },
              {
                "glyph" : 72,
                "width" : 9216,
                "is-cluster-start" : true,
                "log-cluster" : 1
              },
              {
                "glyph" : 79,
                "width" : 5120,
                "is-cluster-start" : true,
                "log-cluster" : 2
              },
              {
                "glyph" : 79,
                "width" : 5120,
                "is-cluster-start" : true,
                "log-cluster" : 3
              },
              {
                "glyph" : 82,
                "width" : 10240,
                "is-cluster-start" : true,
                "log-cluster" : 4
              },
              {
                "glyph" : 15,
                "width" : 5120,
                "is-cluster-start" : true,
                "log-cluster" : 5
              },
              {
                "glyph" : 3,
                "width" : 5120,
                "is-cluster-start" : true,
                "log-cluster" : 6
              }
            ]
          },
          {
            "offset" : 7,
            "length" : 6,
            "text" : "Παν",
            "bidi-level" : 0,
            "gravity" : "south",
            "language" : "c",
            "script" : "greek",
            "font" : {
              "description" : "DejaVu Serif 12",
              "checksum" : "%s",
              "matrix" : [
                1,
                -0,
                -0,
                1,
                0,
                0
              ]
            },
            "flags" : 0,
            "y-offset" : 0,
            "start-x-offset" : 0,
            "end-x-offset" : 0,
            "glyphs" : [
              {
                "glyph" : 794,
                "width" : 14336,
                "is-cluster-start" : true,
                "log-cluster" : 0
              },
              {
                "glyph" : 810,
                "width" : 11264,
                "is-cluster-start" : true,
                "log-cluster" : 2
              },
              {
                "glyph" : 822,
                "width" : 10240,
                "is-cluster-start" : true,
                "log-cluster" : 4
              }
            ]
          },
          {
            "offset" : 13,
            "length" : 3,
            "text" : "語",
            "bidi-level" : 0,
            "gravity" : "south",
            "language" : "c",
            "script" : "han",
            "font" : {
              "description" : "Noto Sans CJK %s 12",
              "checksum" : "%s",
              "matrix" : [
                1,
                -0,
                -0,
                1,
                0,
                0
              ]
            },
            "flags" : 0,
            "y-offset" : 0,
            "start-x-offset" : 0,
            "end-x-offset" : 0,
            "glyphs" : [
              {
                "glyph" : 37860,
                "width" : 16384,
                "is-cluster-start" : true,
                "log-cluster" : 0
              }
            ]
          },
          {
            "offset" : 16,
            "length" : 1,
            "text" : "!",
            "bidi-level" : 0,
            "gravity" : "south",
            "language" : "c",
            "script" : "han",
            "font" : {
              "description" : "DejaVu Serif 12",
              "checksum" : "%s",
              "matrix" : [
                1,
                -0,
                -0,
                1,
                0,
                0
              ]
            },
            "flags" : 0,
            "y-offset" : 0,
            "start-x-offset" : 0,
            "end-x-offset" : 0,
            "glyphs" : [
              {
                "glyph" : 4,
                "width" : 6144,
                "is-cluster-start" : true,
                "log-cluster" : 0
              }
            ]
          }
        ]
      }
    ]
  }
}
"
Pango\Layout::serialize() expects at most 1 argument, 2 given
Pango\Layout::serialize(): Argument #1 ($flags) must be of type int, array given
