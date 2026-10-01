--TEST--
Pango extension function listing
--SKIPIF--
<?php
include __DIR__ . '/skipif.php.inc';
if (strtolower(PHP_OS_FAMILY) !== 'linux') {
    die('skip - This test is for Linux only');
}
?>
--FILE--
<?php
var_dump(get_extension_funcs('pango'));
?>
--EXPECT--
array(15) {
  [0]=>
  string(29) "Pango\find_paragraph_boundary"
  [1]=>
  string(13) "Pango\version"
  [2]=>
  string(20) "Pango\version_string"
  [3]=>
  string(19) "Pango\version_check"
  [4]=>
  string(18) "Pango\parse_markup"
  [5]=>
  string(19) "Pango\is_zero_width"
  [6]=>
  string(34) "Pango\log2vis_get_embedding_levels"
  [7]=>
  string(19) "Pango\reorder_items"
  [8]=>
  string(21) "Pango\units_to_double"
  [9]=>
  string(23) "Pango\units_from_double"
  [10]=>
  string(28) "Pango\quantize_line_geometry"
  [11]=>
  string(11) "Pango\shape"
  [12]=>
  string(16) "Pango\shape_full"
  [13]=>
  string(16) "Pango\shape_item"
  [14]=>
  string(22) "Pango\shape_with_flags"
}
