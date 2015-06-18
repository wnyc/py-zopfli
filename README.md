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

Both zopfli.zlib.compress and zopfli.gzip.compress support the
following keyword arguements.  All values should be integers; boolean
parmaters are treated as expected, 0 and >0 as false and true.

* *verbose* dumps zopfli debugging data to stderr

* *numiterations*   Maximum amount of times to rerun forward and backward pass to optimize LZ77
  compression cost. Good values: 10, 15 for small files, 5 for files over
  several MB in size or it will be too slow. Default value: 15.

* *blocksplitting*  If true, splits the data in multiple deflate blocks with optimal choice
  for the block boundaries. Block splitting gives better compression. Default:
  true (1).
 
* *blocksplittinglast* If true, chooses the optimal block split points only after doing the iterative
  LZ77 compression. If false, chooses the block split points first, then does
  iterative LZ77 on each individual block. Depending on the file, either first
  or last gives the best compression. Default: false (0).
 
* *blocksplittingmax* Maximum amount of blocks to split into (0 for unlimited, but this can give
  extreme results that hurt compression on some files). Default value: 15.

[zopfli]: http://googledevelopers.blogspot.com/2013/02/compress-data-more-densely-with-zopfli.html

TODO
====

* Stop reading the entire file into memory and support streaming

* Monkey patch zlib and gzip so code with an overly tight binding can
  be easily modified to use zopfli.

