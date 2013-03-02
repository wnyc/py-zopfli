PYZOPFLI
========

cPython bindings for [zopfli][zopfli].


USAGE
=====

pyzopfli is a straight forward wrapper around [zopfli's][zopfli]'s ZlibCompress method.

    from zopfli.zlib import compress
    from zlib import decompress
    s = 'Hello World'
    print decompress(compress(s))
    

pyzopfli also wrapps GzipCompress, but the API point does not try to mimic the gzip module. 

    from zopfli.gzip import compress 
    from StringIO import StringIO
    from gzip import GzipFile
    print GzipFile(fileobj=StringIO(compress("Hello World!"))).read()


[zopfli]: http://googledevelopers.blogspot.com/2013/02/compress-data-more-densely-with-zopfli.html

TODO
====

* Support zopfli parameters

* Monkey patch zlib and gzip so code with an overly tight binding can
  be easily modified to use zopfli.

