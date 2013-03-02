PYZOPFLI
========

C Python bindings for zopfli.


USAGE
=====


import zopfli.zlib
import zlib

s = 'Hello World'

print zlib.decompress(zopfli.zlib.compress(s))
# You can also say zopfli.gzip.compress(s), but zopfli isn't gzip compatible yet                                                                                          

