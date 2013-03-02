PYZOPFLI
========

cPython bindings for [zopfli][zopfli].


USAGE
=====

pyzopfil is a straight forward wrapper around [zopfli's][zopfli]'s ZlibCompress method.

    from zopfli.zlib import compress
    from zlib import decompress
    s = 'Hello World'
    print decompress(compress(s))
    

[zopfli]: http://googledevelopers.blogspot.com/2013/02/compress-data-more-densely-with-zopfli.html
Google's announcement of zopfli

TODO
====

* Support zopfli parameters

* Monkey patch zlib and gzip so code with an overly tight binding can
  be easily modified to use zopfli.

