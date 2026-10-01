<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * The Script enumeration identifies different writing systems.
 *
 * The values correspond to the names as defined in the Unicode standard.
 * See Unicode Standard Annex 24: Script names
 */

// Note that this enumeration is based on the GUnicodeScript enumeration and
// not the deprecated PangoScript one as it is not updated to include
// values of newer versions of the Unicode standard.
// The values of GUnicodeScript and PangoScript are interchangeable.

enum Script: int
{
    /**
     * This value is used to indicate that a script is unknown because it is
     * not yet supported by the pango extension.
     */
    case UnknownNewScript = -9999;

    /**
     * @cvalue G_UNICODE_SCRIPT_INVALID_CODE
     */
    case InvalidCode = UNKNOWN;

    /**
     * a character used by multiple different scripts
     *
     * @cvalue G_UNICODE_SCRIPT_COMMON
     */
    case Common = UNKNOWN;

    /**
     * a mark glyph that takes its script from the base glyph to which it is attached
     *
     * @cvalue G_UNICODE_SCRIPT_INHERITED
     */
    case Inherited = UNKNOWN;

    /**
     * Arabic
     *
     * @cvalue G_UNICODE_SCRIPT_ARABIC
     */
    case Arabic = UNKNOWN;

    /**
     * Armenian
     *
     * @cvalue G_UNICODE_SCRIPT_ARMENIAN
     */
    case Armenian = UNKNOWN;

    /**
     * Bengali
     *
     * @cvalue G_UNICODE_SCRIPT_BENGALI
     */
    case Bengali = UNKNOWN;

    /**
     * Bopomofo
     *
     * @cvalue G_UNICODE_SCRIPT_BOPOMOFO
     */
    case Bopomofo = UNKNOWN;

    /**
     * Cherokee
     *
     * @cvalue G_UNICODE_SCRIPT_CHEROKEE
     */
    case Cherokee = UNKNOWN;

    /**
     * Coptic
     *
     * @cvalue G_UNICODE_SCRIPT_COPTIC
     */
    case Coptic = UNKNOWN;

    /**
     * Cyrillic
     *
     * @cvalue G_UNICODE_SCRIPT_CYRILLIC
     */
    case Cyrillic = UNKNOWN;

    /**
     * Deseret
     *
     * @cvalue G_UNICODE_SCRIPT_DESERET
     */
    case Deseret = UNKNOWN;

    /**
     * Devanagari
     *
     * @cvalue G_UNICODE_SCRIPT_DEVANAGARI
     */
    case Devanagari = UNKNOWN;

    /**
     * Ethiopic
     *
     * @cvalue G_UNICODE_SCRIPT_ETHIOPIC
     */
    case Ethiopic = UNKNOWN;

    /**
     * Georgian
     *
     * @cvalue G_UNICODE_SCRIPT_GEORGIAN
     */
    case Georgian = UNKNOWN;

    /**
     * Gothic
     *
     * @cvalue G_UNICODE_SCRIPT_GOTHIC
     */
    case Gothic = UNKNOWN;

    /**
     * Greek
     *
     * @cvalue G_UNICODE_SCRIPT_GREEK
     */
    case Greek = UNKNOWN;

    /**
     * Gujarati
     *
     * @cvalue G_UNICODE_SCRIPT_GUJARATI
     */
    case Gujarati = UNKNOWN;

    /**
     * Gurmukhi
     *
     * @cvalue G_UNICODE_SCRIPT_GURMUKHI
     */
    case Gurmukhi = UNKNOWN;

    /**
     * Han
     *
     * @cvalue G_UNICODE_SCRIPT_HAN
     */
    case Han = UNKNOWN;

    /**
     * Hangul
     *
     * @cvalue G_UNICODE_SCRIPT_HANGUL
     */
    case Hangul = UNKNOWN;

    /**
     * Hebrew
     *
     * @cvalue G_UNICODE_SCRIPT_HEBREW
     */
    case Hebrew = UNKNOWN;

    /**
     * Hiragana
     *
     * @cvalue G_UNICODE_SCRIPT_HIRAGANA
     */
    case Hiragana = UNKNOWN;

    /**
     * Kannada
     *
     * @cvalue G_UNICODE_SCRIPT_KANNADA
     */
    case Kannada = UNKNOWN;

    /**
     * Katakana
     *
     * @cvalue G_UNICODE_SCRIPT_KATAKANA
     */
    case Katakana = UNKNOWN;

    /**
     * Khmer
     *
     * @cvalue G_UNICODE_SCRIPT_KHMER
     */
    case Khmer = UNKNOWN;

    /**
     * Lao
     *
     * @cvalue G_UNICODE_SCRIPT_LAO
     */
    case Lao = UNKNOWN;

    /**
     * Latin
     *
     * @cvalue G_UNICODE_SCRIPT_LATIN
     */
    case Latin = UNKNOWN;

    /**
     * Malayalam
     *
     * @cvalue G_UNICODE_SCRIPT_MALAYALAM
     */
    case Malayalam = UNKNOWN;

    /**
     * Mongolian
     *
     * @cvalue G_UNICODE_SCRIPT_MONGOLIAN
     */
    case Mongolian = UNKNOWN;

    /**
     * Myanmar
     *
     * @cvalue G_UNICODE_SCRIPT_MYANMAR
     */
    case Myanmar = UNKNOWN;

    /**
     * Ogham
     *
     * @cvalue G_UNICODE_SCRIPT_OGHAM
     */
    case Ogham = UNKNOWN;

    /**
     * Old Italic
     *
     * @cvalue G_UNICODE_SCRIPT_OLD_ITALIC
     */
    case Old_Italic = UNKNOWN;

    /**
     * Oriya
     *
     * @cvalue G_UNICODE_SCRIPT_ORIYA
     */
    case Oriya = UNKNOWN;

    /**
     * Runic
     *
     * @cvalue G_UNICODE_SCRIPT_RUNIC
     */
    case Runic = UNKNOWN;

    /**
     * Sinhala
     *
     * @cvalue G_UNICODE_SCRIPT_SINHALA
     */
    case Sinhala = UNKNOWN;

    /**
     * Syriac
     *
     * @cvalue G_UNICODE_SCRIPT_SYRIAC
     */
    case Syriac = UNKNOWN;

    /**
     * Tamil
     *
     * @cvalue G_UNICODE_SCRIPT_TAMIL
     */
    case Tamil = UNKNOWN;

    /**
     * Telugu
     *
     * @cvalue G_UNICODE_SCRIPT_TELUGU
     */
    case Telugu = UNKNOWN;

    /**
     * Thaana
     *
     * @cvalue G_UNICODE_SCRIPT_THAANA
     */
    case Thaana = UNKNOWN;

    /**
     * Thai
     *
     * @cvalue G_UNICODE_SCRIPT_THAI
     */
    case Thai = UNKNOWN;

    /**
     * Tibetan
     *
     * @cvalue G_UNICODE_SCRIPT_TIBETAN
     */
    case Tibetan = UNKNOWN;

    /**
     * Canadian Aboriginal
     *
     * @cvalue G_UNICODE_SCRIPT_CANADIAN_ABORIGINAL
     */
    case CanadianAboriginal = UNKNOWN;

    /**
     * Yi
     *
     * @cvalue G_UNICODE_SCRIPT_YI
     */
    case Yi = UNKNOWN;

    /**
     * Tagalog
     *
     * @cvalue G_UNICODE_SCRIPT_TAGALOG
     */
    case Tagalog = UNKNOWN;

    /**
     * Hanunoo
     *
     * @cvalue G_UNICODE_SCRIPT_HANUNOO
     */
    case Hanunoo = UNKNOWN;

    /**
     * Buhid
     *
     * @cvalue G_UNICODE_SCRIPT_BUHID
     */
    case Buhid = UNKNOWN;

    /**
     * Tagbanwa
     *
     * @cvalue G_UNICODE_SCRIPT_TAGBANWA
     */
    case Tagbanwa = UNKNOWN;

    /**
     * Braille
     *
     * @cvalue G_UNICODE_SCRIPT_BRAILLE
     */
    case Braille = UNKNOWN;

    /**
     * Cypriot
     *
     * @cvalue G_UNICODE_SCRIPT_CYPRIOT
     */
    case Cypriot = UNKNOWN;

    /**
     * Limbu
     *
     * @cvalue G_UNICODE_SCRIPT_LIMBU
     */
    case Limbu = UNKNOWN;

    /**
     * Osmanya
     *
     * @cvalue G_UNICODE_SCRIPT_OSMANYA
     */
    case Osmanya = UNKNOWN;

    /**
     * Shavian
     *
     * @cvalue G_UNICODE_SCRIPT_SHAVIAN
     */
    case Shavian = UNKNOWN;

    /**
     * Linear B
     *
     * @cvalue G_UNICODE_SCRIPT_LINEAR_B
     */
    case LinearB = UNKNOWN;

    /**
     * Tai Le
     *
     * @cvalue G_UNICODE_SCRIPT_TAI_LE
     */
    case TaiLe = UNKNOWN;

    /**
     * Ugaritic
     *
     * @cvalue G_UNICODE_SCRIPT_UGARITIC
     */
    case Ugaritic = UNKNOWN;

    /**
     * New Tai Lue
     *
     * @cvalue G_UNICODE_SCRIPT_NEW_TAI_LUE
     */
    case NewTaiLue = UNKNOWN;

    /**
     * Buginese
     *
     * @cvalue G_UNICODE_SCRIPT_BUGINESE
     */
    case Buginese = UNKNOWN;

    /**
     * Glagolitic
     *
     * @cvalue G_UNICODE_SCRIPT_GLAGOLITIC
     */
    case Glagolitic = UNKNOWN;

    /**
     * Tifinagh
     *
     * @cvalue G_UNICODE_SCRIPT_TIFINAGH
     */
    case Tifinagh = UNKNOWN;

    /**
     * Syloti Nagri
     *
     * @cvalue G_UNICODE_SCRIPT_SYLOTI_NAGRI
     */
    case SylotiNagri = UNKNOWN;

    /**
     * Old Persian
     *
     * @cvalue G_UNICODE_SCRIPT_OLD_PERSIAN
     */
    case OldPersian = UNKNOWN;

    /**
     * Kharoshthi
     *
     * @cvalue G_UNICODE_SCRIPT_KHAROSHTHI
     */
    case Kharoshthi = UNKNOWN;

    /**
     * an unassigned code point
     *
     * @cvalue G_UNICODE_SCRIPT_UNKNOWN
     */
    case Unknown = UNKNOWN;

    /**
     * Balinese
     *
     * @cvalue G_UNICODE_SCRIPT_BALINESE
     */
    case Balinese = UNKNOWN;

    /**
     * Cuneiform
     *
     * @cvalue G_UNICODE_SCRIPT_CUNEIFORM
     */
    case Cuneiform = UNKNOWN;

    /**
     * Phoenician
     *
     * @cvalue G_UNICODE_SCRIPT_PHOENICIAN
     */
    case Phoenician = UNKNOWN;

    /**
     * Phags-pa
     *
     * @cvalue G_UNICODE_SCRIPT_PHAGS_PA
     */
    case PhagsPa = UNKNOWN;

    /**
     * N’Ko
     *
     * @cvalue G_UNICODE_SCRIPT_NKO
     */
    case Nko = UNKNOWN;

#if GLIB_CHECK_VERSION(2, 16, 3)
    /**
     * Kayah Li
     *
     * @cvalue G_UNICODE_SCRIPT_KAYAH_LI
     */
    case KayahLi = UNKNOWN;

    /**
     * Lepcha
     *
     * @cvalue G_UNICODE_SCRIPT_LEPCHA
     */
    case Lepcha = UNKNOWN;

    /**
     * Rejang
     *
     * @cvalue G_UNICODE_SCRIPT_REJANG
     */
    case Rejang = UNKNOWN;

    /**
     * Sundanese
     *
     * @cvalue G_UNICODE_SCRIPT_SUNDANESE
     */
    case Sundanese = UNKNOWN;

    /**
     * Saurashtra
     *
     * @cvalue G_UNICODE_SCRIPT_SAURASHTRA
     */
    case Saurashtra = UNKNOWN;

    /**
     * Cham
     *
     * @cvalue G_UNICODE_SCRIPT_CHAM
     */
    case Cham = UNKNOWN;

    /**
     * Ol Chiki
     *
     * @cvalue G_UNICODE_SCRIPT_OL_CHIKI
     */
    case OlChiki = UNKNOWN;

    /**
     * Vai
     *
     * @cvalue G_UNICODE_SCRIPT_VAI
     */
    case Vai = UNKNOWN;

    /**
     * Carian
     *
     * @cvalue G_UNICODE_SCRIPT_CARIAN
     */
    case Carian = UNKNOWN;

    /**
     * Lycian
     *
     * @cvalue G_UNICODE_SCRIPT_LYCIAN
     */
    case Lycian = UNKNOWN;

    /**
     * Lydian
     *
     * @cvalue G_UNICODE_SCRIPT_LYDIAN
     */
    case Lydian = UNKNOWN;
#endif

#if GLIB_CHECK_VERSION(2, 26, 0)
    /**
     * Avestan
     *
     * @cvalue G_UNICODE_SCRIPT_AVESTAN
     */
    case Avestan = UNKNOWN;

    /**
     * Bamum
     *
     * @cvalue G_UNICODE_SCRIPT_BAMUM
     */
    case Bamum = UNKNOWN;

    /**
     * Egyptian Hieroglyphs
     *
     * @cvalue G_UNICODE_SCRIPT_EGYPTIAN_HIEROGLYPHS
     */
    case EgyptianHieroglyphs = UNKNOWN;

    /**
     * Imperial Aramaic
     *
     * @cvalue G_UNICODE_SCRIPT_IMPERIAL_ARAMAIC
     */
    case ImperialAramaic = UNKNOWN;

    /**
     * Inscriptional Pahlavi
     *
     * @cvalue G_UNICODE_SCRIPT_INSCRIPTIONAL_PAHLAVI
     */
    case InscriptionalPahlavi = UNKNOWN;

    /**
     * Inscriptional Parthian
     *
     * @cvalue G_UNICODE_SCRIPT_INSCRIPTIONAL_PARTHIAN
     */
    case InscriptionalParthian = UNKNOWN;

    /**
     * Javanese
     *
     * @cvalue G_UNICODE_SCRIPT_JAVANESE
     */
    case Javanese = UNKNOWN;

    /**
     * Kaithi
     *
     * @cvalue G_UNICODE_SCRIPT_KAITHI
     */
    case Kaithi = UNKNOWN;

    /**
     * Lisu
     *
     * @cvalue G_UNICODE_SCRIPT_LISU
     */
    case Lisu = UNKNOWN;

    /**
     * Meetei Mayek
     *
     * @cvalue G_UNICODE_SCRIPT_MEETEI_MAYEK
     */
    case MeeteiMayek = UNKNOWN;

    /**
     * Old South Arabian
     *
     * @cvalue G_UNICODE_SCRIPT_OLD_SOUTH_ARABIAN
     */
    case OldSouthArabian = UNKNOWN;

    /**
     * Samaritan
     *
     * @cvalue G_UNICODE_SCRIPT_SAMARITAN
     */
    case Samaritan = UNKNOWN;

    /**
     * Tai Tham
     *
     * @cvalue G_UNICODE_SCRIPT_TAI_THAM
     */
    case TaiTham = UNKNOWN;

    /**
     * Tai Viet
     *
     * @cvalue G_UNICODE_SCRIPT_TAI_VIET
     */
    case TaiViet = UNKNOWN;
#endif

#if GLIB_CHECK_VERSION(2, 28, 0)
    /**
     * Old Turkic
     *
     * @cvalue G_UNICODE_SCRIPT_OLD_TURKIC
     */
    case OldTurkic = UNKNOWN;

    /**
     * Batak
     *
     * @cvalue G_UNICODE_SCRIPT_BATAK
     */
    case Batak = UNKNOWN;

    /**
     * Brahmi
     *
     * @cvalue G_UNICODE_SCRIPT_BRAHMI
     */
    case Brahmi = UNKNOWN;

    /**
     * Mandaic
     *
     * @cvalue G_UNICODE_SCRIPT_MANDAIC
     */
    case Mandaic = UNKNOWN;
#endif

#if GLIB_CHECK_VERSION(2, 32, 0)
    /**
     * Chakma
     *
     * @cvalue G_UNICODE_SCRIPT_CHAKMA
     */
    case Chakma = UNKNOWN;

    /**
     * Meroitic Cursive
     *
     * @cvalue G_UNICODE_SCRIPT_MEROITIC_CURSIVE
     */
    case MeroiticCursive = UNKNOWN;

    /**
     * Meroitic Hieroglyphs
     *
     * @cvalue G_UNICODE_SCRIPT_MEROITIC_HIEROGLYPHS
     */
    case MeroiticHieroglyphs = UNKNOWN;

    /**
     * Miao
     *
     * @cvalue G_UNICODE_SCRIPT_MIAO
     */
    case Miao = UNKNOWN;

    /**
     * Sharada
     *
     * @cvalue G_UNICODE_SCRIPT_SHARADA
     */
    case Sharada = UNKNOWN;

    /**
     * Sora Sompeng
     *
     * @cvalue G_UNICODE_SCRIPT_SORA_SOMPENG
     */
    case SoraSompeng = UNKNOWN;

    /**
     * Takri
     *
     * @cvalue G_UNICODE_SCRIPT_TAKRI
     */
    case Takri = UNKNOWN;
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
    /**
     * Bassa
     *
     * @cvalue G_UNICODE_SCRIPT_BASSA_VAH
     */
    case BassaVah = UNKNOWN;

    /**
     * Caucasian Albanian
     *
     * @cvalue G_UNICODE_SCRIPT_CAUCASIAN_ALBANIAN
     */
    case CaucasianAlbanian = UNKNOWN;

    /**
     * Duployan
     *
     * @cvalue G_UNICODE_SCRIPT_DUPLOYAN
     */
    case Duployan = UNKNOWN;

    /**
     * Elbasan
     *
     * @cvalue G_UNICODE_SCRIPT_ELBASAN
     */
    case Elbasan = UNKNOWN;

    /**
     * Grantha
     *
     * @cvalue G_UNICODE_SCRIPT_GRANTHA
     */
    case Grantha = UNKNOWN;

    /**
     * Kjohki
     *
     * @cvalue G_UNICODE_SCRIPT_KHOJKI
     */
    case Khojki = UNKNOWN;

    /**
     * Khudawadi, Sindhi
     *
     * @cvalue G_UNICODE_SCRIPT_KHUDAWADI
     */
    case Khudawadi = UNKNOWN;

    /**
     * Linear A
     *
     * @cvalue G_UNICODE_SCRIPT_LINEAR_A
     */
    case LinearA = UNKNOWN;

    /**
     * Mahajani
     *
     * @cvalue G_UNICODE_SCRIPT_MAHAJANI
     */
    case Mahajani = UNKNOWN;

    /**
     * Manichaean
     *
     * @cvalue G_UNICODE_SCRIPT_MANICHAEAN
     */
    case Manichaean = UNKNOWN;

    /**
     * Mende Kikakui
     *
     * @cvalue G_UNICODE_SCRIPT_MENDE_KIKAKUI
     */
    case MendeKikakui = UNKNOWN;

    /**
     * Modi
     *
     * @cvalue G_UNICODE_SCRIPT_MODI
     */
    case Modi = UNKNOWN;

    /**
     * Mro
     *
     * @cvalue G_UNICODE_SCRIPT_MRO
     */
    case Mro = UNKNOWN;

    /**
     * Nabataean
     *
     * @cvalue G_UNICODE_SCRIPT_NABATAEAN
     */
    case Nabataean = UNKNOWN;

    /**
     * Old North Arabian
     *
     * @cvalue G_UNICODE_SCRIPT_OLD_NORTH_ARABIAN
     */
    case OldNorthArabian = UNKNOWN;

    /**
     * Old Permic
     *
     * @cvalue G_UNICODE_SCRIPT_OLD_PERMIC
     */
    case OldPermic = UNKNOWN;

    /**
     * Pahawh Hmong
     *
     * @cvalue G_UNICODE_SCRIPT_PAHAWH_HMONG
     */
    case PahawhHmong = UNKNOWN;

    /**
     * Palmyrene
     *
     * @cvalue G_UNICODE_SCRIPT_PALMYRENE
     */
    case Palmyrene = UNKNOWN;

    /**
     * Pau Cin Hau
     *
     * @cvalue G_UNICODE_SCRIPT_PAU_CIN_HAU
     */
    case PauCinHau = UNKNOWN;

    /**
     * Psalter Pahlavi
     *
     * @cvalue G_UNICODE_SCRIPT_PSALTER_PAHLAVI
     */
    case PsalterPahlavi = UNKNOWN;

    /**
     * Siddham
     *
     * @cvalue G_UNICODE_SCRIPT_SIDDHAM
     */
    case Siddham = UNKNOWN;

    /**
     * Tirhuta
     *
     * @cvalue G_UNICODE_SCRIPT_TIRHUTA
     */
    case Tirhuta = UNKNOWN;

    /**
     * Warang Citi
     *
     * @cvalue G_UNICODE_SCRIPT_WARANG_CITI
     */
    case WarangCiti = UNKNOWN;
#endif

#if GLIB_CHECK_VERSION(2, 48, 0)
    /**
     * Ahom
     *
     * @cvalue G_UNICODE_SCRIPT_AHOM
     */
    case Ahom = UNKNOWN;

    /**
     * Anatolian Hieroglyphs
     *
     * @cvalue G_UNICODE_SCRIPT_ANATOLIAN_HIEROGLYPHS
     */
    case AnatolianHieroglyphs = UNKNOWN;

    /**
     * Hatran
     *
     * @cvalue G_UNICODE_SCRIPT_HATRAN
     */
    case Hatran = UNKNOWN;

    /**
     * Multani
     *
     * @cvalue G_UNICODE_SCRIPT_MULTANI
     */
    case Multani = UNKNOWN;

    /**
     * Old Hungarian
     *
     * @cvalue G_UNICODE_SCRIPT_OLD_HUNGARIAN
     */
    case OldHungarian = UNKNOWN;

    /**
     * Signwriting
     *
     * @cvalue G_UNICODE_SCRIPT_SIGNWRITING
     */
    case Signwriting = UNKNOWN;
#endif

#if GLIB_CHECK_VERSION(2, 50, 0)
    /**
     * Adlam
     *
     * @cvalue G_UNICODE_SCRIPT_ADLAM
     */
    case Adlam = UNKNOWN;

    /**
     * Bhaiksuki
     *
     * @cvalue G_UNICODE_SCRIPT_BHAIKSUKI
     */
    case Bhaiksuki = UNKNOWN;

    /**
     * Marchen
     *
     * @cvalue G_UNICODE_SCRIPT_MARCHEN
     */
    case Marchen = UNKNOWN;

    /**
     * Newa
     *
     * @cvalue G_UNICODE_SCRIPT_NEWA
     */
    case Newa = UNKNOWN;

    /**
     * Osage
     *
     * @cvalue G_UNICODE_SCRIPT_OSAGE
     */
    case Osage = UNKNOWN;

    /**
     * Tangut
     *
     * @cvalue G_UNICODE_SCRIPT_TANGUT
     */
    case Tangut = UNKNOWN;
#endif

#if GLIB_CHECK_VERSION(2, 54, 0)
    /**
     * Masaram Gondi
     *
     * @cvalue G_UNICODE_SCRIPT_MASARAM_GONDI
     */
    case MasaramGondi = UNKNOWN;

    /**
     * Nushu
     *
     * @cvalue G_UNICODE_SCRIPT_NUSHU
     */
    case Nushu = UNKNOWN;

    /**
     * Soyombo
     *
     * @cvalue G_UNICODE_SCRIPT_SOYOMBO
     */
    case Soyombo = UNKNOWN;

    /**
     * Zanabazar Square
     *
     * @cvalue G_UNICODE_SCRIPT_ZANABAZAR_SQUARE
     */
    case ZanabazarSquare = UNKNOWN;
#endif

#if GLIB_CHECK_VERSION(2, 58, 0)
    /**
     * Dogra
     *
     * @cvalue G_UNICODE_SCRIPT_DOGRA
     */
    case Dogra = UNKNOWN;

    /**
     * Gunjala Gondi
     *
     * @cvalue G_UNICODE_SCRIPT_GUNJALA_GONDI
     */
    case GunjalaGondi = UNKNOWN;

    /**
     * Hanifi Rohingya
     *
     * @cvalue G_UNICODE_SCRIPT_HANIFI_ROHINGYA
     */
    case HanifiRohingya = UNKNOWN;

    /**
     * Makasar
     *
     * @cvalue G_UNICODE_SCRIPT_MAKASAR
     */
    case Makasar = UNKNOWN;

    /**
     * Medefaidrin
     *
     * @cvalue G_UNICODE_SCRIPT_MEDEFAIDRIN
     */
    case Medefaidrin = UNKNOWN;

    /**
     * Old Sogdian
     *
     * @cvalue G_UNICODE_SCRIPT_OLD_SOGDIAN
     */
    case OldSogdian = UNKNOWN;

    /**
     * Sogdian
     *
     * @cvalue G_UNICODE_SCRIPT_SOGDIAN
     */
    case Sogdian = UNKNOWN;
#endif

#if GLIB_CHECK_VERSION(2, 62, 0)
    /**
     * Elym
     *
     * @cvalue G_UNICODE_SCRIPT_ELYMAIC
     */
    case Elymaic = UNKNOWN;

    /**
     * Nand
     *
     * @cvalue G_UNICODE_SCRIPT_NANDINAGARI
     */
    case Nandinagari = UNKNOWN;

    /**
     * Rohg
     *
     * @cvalue G_UNICODE_SCRIPT_NYIAKENG_PUACHUE_HMONG
     */
    case NyiaKengPuachueHmong = UNKNOWN;

    /**
     * Wcho
     *
     * @cvalue G_UNICODE_SCRIPT_WANCHO
     */
    case Wancho = UNKNOWN;
#endif

#if GLIB_CHECK_VERSION(2, 66, 0)
    /**
     * Chorasmian
     *
     * @cvalue G_UNICODE_SCRIPT_CHORASMIAN
     */
    case Chorasmian = UNKNOWN;

    /**
     * Dives Akuru
     *
     * @cvalue G_UNICODE_SCRIPT_DIVES_AKURU
     */
    case DivesAkuru = UNKNOWN;

    /**
     * Khitan small script
     *
     * @cvalue G_UNICODE_SCRIPT_KHITAN_SMALL_SCRIPT
     */
    case KhitanSmallScript = UNKNOWN;

    /**
     * Yezidi
     *
     * @cvalue G_UNICODE_SCRIPT_YEZIDI
     */
    case Yezidi = UNKNOWN;
#endif

#if GLIB_CHECK_VERSION(2, 72, 0)
    /**
     * Cypro-Minoan
     *
     * @cvalue G_UNICODE_SCRIPT_CYPRO_MINOAN
     */
    case CyproMinoan = UNKNOWN;

    /**
     * Old Uyghur
     *
     * @cvalue G_UNICODE_SCRIPT_OLD_UYGHUR
     */
    case OldUyghur = UNKNOWN;

    /**
     * Tangsa
     *
     * @cvalue G_UNICODE_SCRIPT_TANGSA
     */
    case Tangsa = UNKNOWN;

    /**
     * Toto
     *
     * @cvalue G_UNICODE_SCRIPT_TOTO
     */
    case Toto = UNKNOWN;

    /**
     * Vithkuqi
     *
     * @cvalue G_UNICODE_SCRIPT_VITHKUQI
     */
    case Vithkuqi = UNKNOWN;

    /**
     * Mathematical notation
     *
     * @cvalue G_UNICODE_SCRIPT_MATH
     */
    case Math = UNKNOWN;
#endif

#if GLIB_CHECK_VERSION(2, 74, 0)
    /**
     * Kawi
     *
     * @cvalue G_UNICODE_SCRIPT_KAWI
     */
    case Kawi = UNKNOWN;

    /**
     * Nag Mundari
     *
     * @cvalue G_UNICODE_SCRIPT_NAG_MUNDARI
     */
    case NagMundari = UNKNOWN;
#endif

#if GLIB_CHECK_VERSION(2, 84, 0)
    /**
     * Todhri
     *
     * @cvalue G_UNICODE_SCRIPT_TODHRI
     */
    case Todhri = UNKNOWN;

    /**
     * Garay
     *
     * @cvalue G_UNICODE_SCRIPT_GARAY
     */
    case Garay = UNKNOWN;

    /**
     * Tulu-Tigalari
     *
     * @cvalue G_UNICODE_SCRIPT_TULU_TIGALARI
     */
    case TuluTigalari = UNKNOWN;

    /**
     * Sunuwar
     *
     * @cvalue G_UNICODE_SCRIPT_SUNUWAR
     */
    case Sunuwar = UNKNOWN;

    /**
     * Gurung Khema
     *
     * @cvalue G_UNICODE_SCRIPT_GURUNG_KHEMA
     */
    case GurungKhema = UNKNOWN;

    /**
     * Kirat Rai
     *
     * @cvalue G_UNICODE_SCRIPT_KIRAT_RAI
     */
    case KiratRai = UNKNOWN;

    /**
     * Ol Onal
     *
     * @cvalue G_UNICODE_SCRIPT_OL_ONAL
     */
    case OlOnal = UNKNOWN;
#endif

#if GLIB_CHECK_VERSION(2, 88, 0)
    /**
     * Sidetic
     *
     * @cvalue G_UNICODE_SCRIPT_SIDETIC
     */
    case Sidetic = UNKNOWN;

    /**
     * Tolong Siki
     *
     * @cvalue G_UNICODE_SCRIPT_TOLONG_SIKI
     */
    case TolongSiki = UNKNOWN;

    /**
     * Tai Yo
     *
     * @cvalue G_UNICODE_SCRIPT_TAI_YO
     */
    case TaiYo = UNKNOWN;

    /**
     * Beria Erfe
     *
     * @cvalue G_UNICODE_SCRIPT_BERIA_ERFE
     */
    case BeriaErfe = UNKNOWN;
#endif

    /**
     * Finds a language tag that is reasonably representative of script.
     *
     * The language will usually be the most widely spoken or used language
     * written in that script: for instance, the sample language for
     * Pango\Script::Cyrillic is ru (Russian), the sample language for
     * Pango\Script::Arabic is ar.
     *
     * For some scripts, no sample language will be returned because there is
     * no language that is sufficiently representative. The best example of
     * this is Pango\Script::Han, where various different variants of written
     * Chinese, Japanese, and Korean all use significantly different sets of
     * Han characters and forms of shared characters. No sample language can
     * be provided for many historical scripts as well.
     */
    public function getSampleLanguage(): ?Language {}

    /**
     * Returns the gravity to use in laying out a single character or Item
     * which uses this script.
     *
     * The gravity is determined for this script based on the base gravity,
     * the gravity hint, and the East Asian width.
     *
     * Wide/full-width characters always stand upright, that is, they always
     * take the base gravity, whereas narrow/full-width characters are always
     * rotated in vertical context.
     *
     * If baseGravity is Gravity::Auto, the default value, it is first replaced
     * with the preferred gravity of script.
     */
    public function getGravity(
        Gravity $baseGravity = Gravity::Auto,
        GravityHint $hint = GravityHint::Natural,
        bool $wide = false,
    ): ?Gravity {}
}

// ** Below is the deprecated Script enumeration. It is provided for compatibility with older versions of Pango, but it is recommended to use GUnicodeScript instead.

// * Note that this enumeration is deprecated and will not be updated to include
// * values in newer versions of the Unicode standard. Applications should use
// * the GUnicodeScript enumeration instead, whose values are interchangeable
// * with Script.

// /**
//  * @cvalue PANGO_SCRIPT_INVALID_CODE
//  */
// case InvalidCode = UNKNOWN;

// /**
//  * A character used by multiple different scripts.
//  * @cvalue PANGO_SCRIPT_COMMON
//  */
// case Common = UNKNOWN;

// /**
//  * A character used by multiple different scripts.
//  * @cvalue PANGO_SCRIPT_INHERITED
//  */
// case Inherited = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_ARABIC
//  */
// case Arabic = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_ARMENIAN
//  */
// case Armenian = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_BENGALI
//  */
// case Bengali = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_BOPOMOFO
//  */
// case Bopomofo = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_CHEROKEE
//  */
// case Cherokee = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_COPTIC
//  */
// case Coptic = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_CYRILLIC
//  */
// case Cyrillic = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_DESERET
//  */
// case Deseret = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_DEVANAGARI
//  */
// case Devanagari = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_ETHIOPIC
//  */
// case Ethiopic = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_GEORGIAN
//  */
// case Georgian = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_GOTHIC
//  */
// case Gothic = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_GREEK
//  */
// case Greek = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_GUJARATI
//  */
// case Gujarati = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_GURMUKHI
//  */
// case Gurmukhi = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_HAN
//  */
// case Han = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_HANGUL
//  */
// case Hangul = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_HEBREW
//  */
// case Hebrew = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_HIRAGANA
//  */
// case Hiragana = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_KANNADA
//  */
// case Kannada = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_KATAKANA
//  */
// case Katakana = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_KHMER
//  */
// case Khmer = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_LAO
//  */
// case Lao = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_LATIN
//  */
// case Latin = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_MALAYALAM
//  */
// case Malayalam = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_MONGOLIAN
//  */
// case Mongolian = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_MYANMAR
//  */
// case Myanmar = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_OGHAM
//  */
// case Ogham = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_OLD_ITALIC
//  */
// case OldItalic = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_ORIYA
//  */
// case Oriya = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_RUNIC
//  */
// case Runic = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_SINHALA
//  */
// case Sinhala = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_SYRIAC
//  */
// case Syriac = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_TAMIL
//  */
// case Tamil = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_TELUGU
//  */
// case Telugu = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_THAANA
//  */
// case Thaana = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_THAI
//  */
// case Thai = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_TIBETAN
//  */
// case Tibetan = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_CANADIAN_ABORIGINAL
//  */
// case CanadianAboriginal = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_YI
//  */
// case Yi = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_TAGALOG
//  */
// case Tagalog = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_HANUNOO
//  */
// case Hanunoo = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_BUHID
//  */
// case Buhid = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_TAGBANWA
//  */
// case Tagbanwa = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_BRAILLE
//  */
// case Braille = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_CYPRIOT
//  */
// case Cypriot = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_LIMBU
//  */
// case Limbu = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_OSMANYA
//  */
// case Osmanya = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_SHAVIAN
//  */
// case Shavian = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_LINEAR_B
//  */
// case LinearB = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_TAI_LE
//  */
// case TaiLe = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_UGARITIC
//  */
// case Ugaritic = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_NEW_TAI_LUE
//  */
// case NewTaiLue = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_BUGINESE
//  */
// case Buginese = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_GLAGOLITIC
//  */
// case Glagolitic = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_TIFINAGH
//  */
// case Tifinagh = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_SYLOTI_NAGRI
//  */
// case SylotiNagri = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_OLD_PERSIAN
//  */
// case OldPersian = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_KHAROSHTHI
//  */
// case Kharoshthi = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_UNKNOWN
//  */
// case Unknown = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_BALINESE
//  */
// case Balinese = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_CUNEIFORM
//  */
// case Cuneiform = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_PHOENICIAN
//  */
// case Phoenician = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_PHAGS_PA
//  */
// case PhagsPa = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_NKO
//  */
// case Nko = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_KAYAH_LI
//  */
// case KayahLi = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_LEPCHA
//  */
// case Lepcha = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_SUNDANESE
//  */
// case Sundanese = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_SAURASHTRA
//  */
// case Saurashtra = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_CHAM
//  */
// case Cham = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_OL_CHIKI
//  */
// case OlChiki = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_VAI
//  */
// case Vai = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_CARIAN
//  */
// case Carian = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_LYCIAN
//  */
// case Lycian = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_LYDIAN
//  */
// case Lydian = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_BATAK
//  */
// case Batak = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_BRAHMI
//  */
// case Brahmi = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_MANDAIC
//  */
// case Mandaic = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_CHAKMA
//  */
// case Chakma = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_MEROITIC_CURSIVE
//  */
// case MeroiticCursive = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_MEROITIC_HIEROGLYPHS
//  */
// case MeroiticHieroglyphs = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_MIAO
//  */
// case Miao = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_SHARADA
//  */
// case Sharada = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_SORA_SOMPENG
//  */
// case SoraSompeng = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_TAKRI
//  */
// case Takri = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_BASSA_VAH
//  */
// case BassaVah = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_CAUCASIAN_ALBANIAN
//  */
// case CaucasianAlbanian = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_DUPLOYAN
//  */
// case Duployan = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_ELBASAN
//  */
// case Elbasan = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_GRANTHA
//  */
// case Grantha = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_KHOJKI
//  */
// case Khojki = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_KHUDAWADI
//  */
// case Khudawadi = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_LINEAR_A
//  */
// case LinearA = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_MAHAJANI
//  */
// case Mahajani = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_MANICHAEAN
//  */
// case Manichaean = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_MENDE_KIKAKUI
//  */
// case MendeKikakui = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_MODI
//  */
// case Modi = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_MRO
//  */
// case Mro = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_NABATAEAN
//  */
// case Nabataean = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_OLD_NORTH_ARABIAN
//  */
// case OldNorthArabian = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_OLD_PERMIC
//  */
// case OldPermic = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_PAHAWH_HMONG
//  */
// case PahawhHmong = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_PALMYRENE
//  */
// case Palmyrene = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_PAU_CIN_HAU
//  */
// case PauCinHau = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_PSALTER_PAHLAVI
//  */
// case PsalterPahlavi = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_SIDDHAM
//  */
// case Siddham = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_TIRHUTA
//  */
// case Tirhuta = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_WARANG_CITI
//  */
// case WarangCiti = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_AHOM
//  */
// case Ahom = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_ANATOLIAN_HIEROGLYPHS
//  */
// case AnatolianHieroglyphs = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_HATRAN
//  */
// case Hatran = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_MULTANI
//  */
// case Multani = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_OLD_HUNGARIAN
//  */
// case OldHungarian = UNKNOWN;

// /**
//  * @cvalue PANGO_SCRIPT_SIGNWRITING
//  */
// case SignWriting = UNKNOWN;
