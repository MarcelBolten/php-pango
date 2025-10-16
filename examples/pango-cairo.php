<?php
/**
  * This example is based on the example from the PangoCairo documentation
  * https://docs.gtk.org/PangoCairo/pango_cairo.html#using-pango-with-cairo
  */

define("RADIUS", 220);
define("N_WORDS", 11);
define("FONT", "Noto Sans 27");

function draw_text(Cairo\Context $c) {
    $c->translate(RADIUS, RADIUS);
    $l = new Pango\Layout($c);
    $l->setText("Παν語");
    $desc = new Pango\FontDescription(FONT);
    $l->setFontDescription($desc);

    for ($i = 0; $i < N_WORDS; $i++) {
        $angle = 360.0 * $i / N_WORDS;
        $red = (1 + cos (($angle - 60) * M_PI / 180)) / 2;

        $c->save();
        $c->setSourceRgba($red, 0, 1.0 - $red);
        $c->rotate($angle * M_PI / 180.0);
        $l->updateLayout($c);
        $size = $l->getSize();
        $x = -((float) $size['width'] / Pango\Pango::SCALE) / 2;
        $c->moveTo($x, - RADIUS);
        $l->showLayout();
        $e = $l->getPixelExtents()["ink"];
        $c->rectangle($e->x + $x, $e->y - RADIUS, $e->width, $e->height);
        $c->stroke();
        $c->restore();
    }

    $l->setMarkup("<b>Hello Παν語!</b>\n<i>This</i> is a <u>test.</u>\n<tt>1234567890</tt>\n🐘🪲\n<span foreground='purple'>ا</span><span foreground='red'>َ</span>ل<span foreground='blue'>ْ</span>ع<span foreground='red'>َ</span>ر<span foreground='red'>َ</span>ب<span foreground='red'>ِ</span>ي<span foreground='green'>ّ</span><span foreground='red'>َ</span>ة<span foreground='blue'>ُ</span>");
    $c->setSourceRgba(0, 0, 0);
    $size = $l->getPixelSize();
    $c->moveTo(- $size['width']/2, - $size['height']/2);
    $l->showLayout();
    $c->fill();
    $c->rectangle(- $size['width']/2, - $size['height']/2, $size['width'], $size['height']);
    $c->stroke();
    unset($desc, $l);
}

$s = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, RADIUS *2, RADIUS *2);
$c = new Cairo\Context($s);
$c->setSourceRgba(0.8, 0.8, 0.8);
$c->paint();
draw_text($c);
$s->writeToPng('circle.png');
unset($c, $s);
