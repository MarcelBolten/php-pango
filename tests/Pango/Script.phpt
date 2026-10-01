--TEST--
Pango\Script enum
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Script;
use Pango\Gravity;
use Pango\GravityHint;

var_dump(Script::cases());

var_dump(Script::Arabic->getSampleLanguage()); // 2
var_dump(Script::Han->getSampleLanguage()); // 17
var_dump(Script::BeriaErfe->getSampleLanguage()); // 175
var_dump(Script::InvalidCode->getSampleLanguage()); // -1
var_dump(Script::UnknownNewScript->getSampleLanguage()); // -9999

try {
    var_dump(Script::Hebrew->getSampleLanguage(1));
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

var_dump(Script::Arabic->getGravity()); // 2
var_dump(Script::InvalidCode->getGravity()); // -1
var_dump(Script::UnknownNewScript->getGravity()); // -9999
var_dump(Script::Han->getGravity()); // 17
var_dump(Script::Han->getGravity(Gravity::Auto, GravityHint::Strong)); // 17

try {
    var_dump(Script::Hebrew->getGravity(Gravity::Auto, GravityHint::Strong, true, 1));
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    var_dump(Script::Hebrew->getGravity(array(), GravityHint::Strong, true));
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    var_dump(Script::Hebrew->getGravity(Gravity::Auto, array(), true));
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    var_dump(Script::Hebrew->getGravity(Gravity::Auto, GravityHint::Strong, array()));
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
array(178) {
  [0]=>
  enum(Pango\Script::UnknownNewScript)
  [1]=>
  enum(Pango\Script::InvalidCode)
  [2]=>
  enum(Pango\Script::Common)
  [3]=>
  enum(Pango\Script::Inherited)
  [4]=>
  enum(Pango\Script::Arabic)
  [5]=>
  enum(Pango\Script::Armenian)
  [6]=>
  enum(Pango\Script::Bengali)
  [7]=>
  enum(Pango\Script::Bopomofo)
  [8]=>
  enum(Pango\Script::Cherokee)
  [9]=>
  enum(Pango\Script::Coptic)
  [10]=>
  enum(Pango\Script::Cyrillic)
  [11]=>
  enum(Pango\Script::Deseret)
  [12]=>
  enum(Pango\Script::Devanagari)
  [13]=>
  enum(Pango\Script::Ethiopic)
  [14]=>
  enum(Pango\Script::Georgian)
  [15]=>
  enum(Pango\Script::Gothic)
  [16]=>
  enum(Pango\Script::Greek)
  [17]=>
  enum(Pango\Script::Gujarati)
  [18]=>
  enum(Pango\Script::Gurmukhi)
  [19]=>
  enum(Pango\Script::Han)
  [20]=>
  enum(Pango\Script::Hangul)
  [21]=>
  enum(Pango\Script::Hebrew)
  [22]=>
  enum(Pango\Script::Hiragana)
  [23]=>
  enum(Pango\Script::Kannada)
  [24]=>
  enum(Pango\Script::Katakana)
  [25]=>
  enum(Pango\Script::Khmer)
  [26]=>
  enum(Pango\Script::Lao)
  [27]=>
  enum(Pango\Script::Latin)
  [28]=>
  enum(Pango\Script::Malayalam)
  [29]=>
  enum(Pango\Script::Mongolian)
  [30]=>
  enum(Pango\Script::Myanmar)
  [31]=>
  enum(Pango\Script::Ogham)
  [32]=>
  enum(Pango\Script::Old_Italic)
  [33]=>
  enum(Pango\Script::Oriya)
  [34]=>
  enum(Pango\Script::Runic)
  [35]=>
  enum(Pango\Script::Sinhala)
  [36]=>
  enum(Pango\Script::Syriac)
  [37]=>
  enum(Pango\Script::Tamil)
  [38]=>
  enum(Pango\Script::Telugu)
  [39]=>
  enum(Pango\Script::Thaana)
  [40]=>
  enum(Pango\Script::Thai)
  [41]=>
  enum(Pango\Script::Tibetan)
  [42]=>
  enum(Pango\Script::CanadianAboriginal)
  [43]=>
  enum(Pango\Script::Yi)
  [44]=>
  enum(Pango\Script::Tagalog)
  [45]=>
  enum(Pango\Script::Hanunoo)
  [46]=>
  enum(Pango\Script::Buhid)
  [47]=>
  enum(Pango\Script::Tagbanwa)
  [48]=>
  enum(Pango\Script::Braille)
  [49]=>
  enum(Pango\Script::Cypriot)
  [50]=>
  enum(Pango\Script::Limbu)
  [51]=>
  enum(Pango\Script::Osmanya)
  [52]=>
  enum(Pango\Script::Shavian)
  [53]=>
  enum(Pango\Script::LinearB)
  [54]=>
  enum(Pango\Script::TaiLe)
  [55]=>
  enum(Pango\Script::Ugaritic)
  [56]=>
  enum(Pango\Script::NewTaiLue)
  [57]=>
  enum(Pango\Script::Buginese)
  [58]=>
  enum(Pango\Script::Glagolitic)
  [59]=>
  enum(Pango\Script::Tifinagh)
  [60]=>
  enum(Pango\Script::SylotiNagri)
  [61]=>
  enum(Pango\Script::OldPersian)
  [62]=>
  enum(Pango\Script::Kharoshthi)
  [63]=>
  enum(Pango\Script::Unknown)
  [64]=>
  enum(Pango\Script::Balinese)
  [65]=>
  enum(Pango\Script::Cuneiform)
  [66]=>
  enum(Pango\Script::Phoenician)
  [67]=>
  enum(Pango\Script::PhagsPa)
  [68]=>
  enum(Pango\Script::Nko)
  [69]=>
  enum(Pango\Script::KayahLi)
  [70]=>
  enum(Pango\Script::Lepcha)
  [71]=>
  enum(Pango\Script::Rejang)
  [72]=>
  enum(Pango\Script::Sundanese)
  [73]=>
  enum(Pango\Script::Saurashtra)
  [74]=>
  enum(Pango\Script::Cham)
  [75]=>
  enum(Pango\Script::OlChiki)
  [76]=>
  enum(Pango\Script::Vai)
  [77]=>
  enum(Pango\Script::Carian)
  [78]=>
  enum(Pango\Script::Lycian)
  [79]=>
  enum(Pango\Script::Lydian)
  [80]=>
  enum(Pango\Script::Avestan)
  [81]=>
  enum(Pango\Script::Bamum)
  [82]=>
  enum(Pango\Script::EgyptianHieroglyphs)
  [83]=>
  enum(Pango\Script::ImperialAramaic)
  [84]=>
  enum(Pango\Script::InscriptionalPahlavi)
  [85]=>
  enum(Pango\Script::InscriptionalParthian)
  [86]=>
  enum(Pango\Script::Javanese)
  [87]=>
  enum(Pango\Script::Kaithi)
  [88]=>
  enum(Pango\Script::Lisu)
  [89]=>
  enum(Pango\Script::MeeteiMayek)
  [90]=>
  enum(Pango\Script::OldSouthArabian)
  [91]=>
  enum(Pango\Script::Samaritan)
  [92]=>
  enum(Pango\Script::TaiTham)
  [93]=>
  enum(Pango\Script::TaiViet)
  [94]=>
  enum(Pango\Script::OldTurkic)
  [95]=>
  enum(Pango\Script::Batak)
  [96]=>
  enum(Pango\Script::Brahmi)
  [97]=>
  enum(Pango\Script::Mandaic)
  [98]=>
  enum(Pango\Script::Chakma)
  [99]=>
  enum(Pango\Script::MeroiticCursive)
  [100]=>
  enum(Pango\Script::MeroiticHieroglyphs)
  [101]=>
  enum(Pango\Script::Miao)
  [102]=>
  enum(Pango\Script::Sharada)
  [103]=>
  enum(Pango\Script::SoraSompeng)
  [104]=>
  enum(Pango\Script::Takri)
  [105]=>
  enum(Pango\Script::BassaVah)
  [106]=>
  enum(Pango\Script::CaucasianAlbanian)
  [107]=>
  enum(Pango\Script::Duployan)
  [108]=>
  enum(Pango\Script::Elbasan)
  [109]=>
  enum(Pango\Script::Grantha)
  [110]=>
  enum(Pango\Script::Khojki)
  [111]=>
  enum(Pango\Script::Khudawadi)
  [112]=>
  enum(Pango\Script::LinearA)
  [113]=>
  enum(Pango\Script::Mahajani)
  [114]=>
  enum(Pango\Script::Manichaean)
  [115]=>
  enum(Pango\Script::MendeKikakui)
  [116]=>
  enum(Pango\Script::Modi)
  [117]=>
  enum(Pango\Script::Mro)
  [118]=>
  enum(Pango\Script::Nabataean)
  [119]=>
  enum(Pango\Script::OldNorthArabian)
  [120]=>
  enum(Pango\Script::OldPermic)
  [121]=>
  enum(Pango\Script::PahawhHmong)
  [122]=>
  enum(Pango\Script::Palmyrene)
  [123]=>
  enum(Pango\Script::PauCinHau)
  [124]=>
  enum(Pango\Script::PsalterPahlavi)
  [125]=>
  enum(Pango\Script::Siddham)
  [126]=>
  enum(Pango\Script::Tirhuta)
  [127]=>
  enum(Pango\Script::WarangCiti)
  [128]=>
  enum(Pango\Script::Ahom)
  [129]=>
  enum(Pango\Script::AnatolianHieroglyphs)
  [130]=>
  enum(Pango\Script::Hatran)
  [131]=>
  enum(Pango\Script::Multani)
  [132]=>
  enum(Pango\Script::OldHungarian)
  [133]=>
  enum(Pango\Script::Signwriting)
  [134]=>
  enum(Pango\Script::Adlam)
  [135]=>
  enum(Pango\Script::Bhaiksuki)
  [136]=>
  enum(Pango\Script::Marchen)
  [137]=>
  enum(Pango\Script::Newa)
  [138]=>
  enum(Pango\Script::Osage)
  [139]=>
  enum(Pango\Script::Tangut)
  [140]=>
  enum(Pango\Script::MasaramGondi)
  [141]=>
  enum(Pango\Script::Nushu)
  [142]=>
  enum(Pango\Script::Soyombo)
  [143]=>
  enum(Pango\Script::ZanabazarSquare)
  [144]=>
  enum(Pango\Script::Dogra)
  [145]=>
  enum(Pango\Script::GunjalaGondi)
  [146]=>
  enum(Pango\Script::HanifiRohingya)
  [147]=>
  enum(Pango\Script::Makasar)
  [148]=>
  enum(Pango\Script::Medefaidrin)
  [149]=>
  enum(Pango\Script::OldSogdian)
  [150]=>
  enum(Pango\Script::Sogdian)
  [151]=>
  enum(Pango\Script::Elymaic)
  [152]=>
  enum(Pango\Script::Nandinagari)
  [153]=>
  enum(Pango\Script::NyiaKengPuachueHmong)
  [154]=>
  enum(Pango\Script::Wancho)
  [155]=>
  enum(Pango\Script::Chorasmian)
  [156]=>
  enum(Pango\Script::DivesAkuru)
  [157]=>
  enum(Pango\Script::KhitanSmallScript)
  [158]=>
  enum(Pango\Script::Yezidi)
  [159]=>
  enum(Pango\Script::CyproMinoan)
  [160]=>
  enum(Pango\Script::OldUyghur)
  [161]=>
  enum(Pango\Script::Tangsa)
  [162]=>
  enum(Pango\Script::Toto)
  [163]=>
  enum(Pango\Script::Vithkuqi)
  [164]=>
  enum(Pango\Script::Math)
  [165]=>
  enum(Pango\Script::Kawi)
  [166]=>
  enum(Pango\Script::NagMundari)
  [167]=>
  enum(Pango\Script::Todhri)
  [168]=>
  enum(Pango\Script::Garay)
  [169]=>
  enum(Pango\Script::TuluTigalari)
  [170]=>
  enum(Pango\Script::Sunuwar)
  [171]=>
  enum(Pango\Script::GurungKhema)
  [172]=>
  enum(Pango\Script::KiratRai)
  [173]=>
  enum(Pango\Script::OlOnal)
  [174]=>
  enum(Pango\Script::Sidetic)
  [175]=>
  enum(Pango\Script::TolongSiki)
  [176]=>
  enum(Pango\Script::TaiYo)
  [177]=>
  enum(Pango\Script::BeriaErfe)
}
object(Pango\Language)#%d (1) {
  ["string-representation"]=>
  string(2) "ar"
}
NULL
NULL
NULL
NULL
Pango\Script::getSampleLanguage() expects exactly 0 arguments, 1 given
enum(Pango\Gravity::South)
NULL
NULL
enum(Pango\Gravity::South)
enum(Pango\Gravity::East)
Pango\Script::getGravity() expects at most 3 arguments, 4 given
Pango\Script::getGravity(): Argument #1 ($baseGravity) must be of type Pango\Gravity, array given
Pango\Script::getGravity(): Argument #2 ($hint) must be of type Pango\GravityHint, array given
Pango\Script::getGravity(): Argument #3 ($wide) must be of type bool, array given
