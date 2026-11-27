--TEST--
Pango\Layout::setText()
--EXTENSIONS--
pango
--SKIPIF--
<?php
if (PHP_OS_FAMILY !== 'Linux') {
    die('skip - only run on Linux');
}
if (getenv('SKIP_ASAN')) {
    die('skip - Uses too much memory under ASAN');
}
if (PHP_INT_SIZE != 8) {
    die('skip - this test is for 64-bit platforms only');
}
$meminfo = @file_get_contents('/proc/meminfo');
if ($meminfo
    && preg_match('/MemAvailable:\s+(\d+) kB/', $meminfo, $m)
    && $m[1] < 2.5 * 1024 * 1024
) {
    die('skip - not enough available memory (need ~2.5 GB)');
}
?>
--INI--
memory_limit=2080M
--FILE--
<?php
use Pango\Ft2\FontMap;

$fontMap = new FontMap();
$pathToFonts = dirname(__FILE__, 3) . "/assets/fonts";
$fontMap->addFontFile($pathToFonts . "/DejaVuSans.ttf");
$fontMap->addFontFile($pathToFonts . "/NotoSansJP-Regular.otf");
$fontMap->addFontFile($pathToFonts . "/NotoSans-Regular.ttf");
$pangoContext = new Pango\Context($fontMap);
$layout = new Pango\Layout($pangoContext);

try {
    $layout->setText(str_repeat("a", 1 << 31));
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
Pango\Layout::setText(): Argument #1 ($text) must be less than or equal to 2147483647 bytes long
