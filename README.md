Pango extension for PHP 8.2+
=============

[Pango](https://www.gtk.org/docs/architecture/pango) is a library for laying out and rendering of text, with an emphasis on internationalization. The name comes from the Greek Παν (“Pan”), meaning “all”, and the Japanese 語 (“Go”), meaning “language”.

This extension provides access to Pango functionality in PHP 8.2+ in the Pango and PangoCairo namespace.

[![Build and Test](https://github.com/MarcelBolten/php-pango/actions/workflows/ci.yml/badge.svg?branch=modern_php)](https://github.com/MarcelBolten/php-pango/actions/workflows/ci.yml)

Requirements
=============
 * PHP 8.2+
 * Pango 1.40+
 * ext-cairo

Features are enabled at compile time based on the library version they are compiled against.

Documentation and information about the underlying library can be found at https://docs.gtk.org/Pango/.

Installation
=============
There are plans to make this available via [PIE (PHP Installer for Extensions)](https://github.com/php/pie)

Until then, please compile and install the pango extensions and enable it in your php.ini file.

```
extension=pango.so
```

Compile
=============

This extension can be compiled and tested using phpize.

The pango extension also requires pango development files.  You can build the package
manually or use your system's package manager.  For example on ubuntu use:

```
apt-get install libpango1.0-dev libcairo2-dev libfreetype6-dev fontconfig
```

Then you can use phpize to install the extension against your current PHP install:

```
phpize
./configure
make && make test && make install
```

If you want to use a non-standard location for your PHP use:

```
/path/to/phpize
./configure --with-php-config=/path/to/php-config
make && make test && make install
```

`make install` copies `pango.so` to the right location, but you still need to enable the module
in your php.ini file.

Codec overage reports
=====================

A [coverage report](https://marcelbolten.github.io/php-pango/src/) is uploaded to gh-pages during every [Build and Test](https://github.com/MarcelBolten/php-pango/actions/workflows/ci.yml) workflow.

Requirements: lcov, gzip.

To obtain a code coverage report the extension must be compiled with additional flags:

```
phpize
PANGO_COVERAGE=yes ./configure
make && make install
coverage.sh
```

This will run all tests and create an html report.

Community
=========
You can send comments, patches, questions [here on github](https://github.com/marcelbolten/php-pango/issues).

Authors
====
Michael Maclean | Marcel Bolten

License
=======
The PHP extension binding code is released under the [PHP License, version 3.01](https://www.php.net/license/3_01.txt)
See [LICENSE](LICENSE)

Parts of the code are based on files from the [cairo extension for PHP](https://github.com/MarcelBolten/php-cairo) which is licensed under the [MIT License](http://www.opensource.org/licenses/mit-license.php)

Pango is released under the [LGPL-2.1-or-later](https://www.gnu.org/licenses/old-licenses/lgpl-2.1.en.html)

Documentation
=============
So far there is only limited documentation available. It is primarily in the code comments and the stub.php files.

There are plans to make the stub files available as an independent composer package.
