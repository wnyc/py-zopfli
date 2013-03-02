#!/usr/bin/env python

import gzip
import unittest
import zlib
import zopfli.gzip
import zopfli.zlib
import StringIO

class Tests(object):
    def test_reversible(self):
        data = unittest.__doc__
        self.assertEquals(self.decompress(self.compress(data)), data)

class ZlibTest(unittest.TestCase, Tests):
    compress = staticmethod(zopfli.zlib.compress)
    decompress = staticmethod(zlib.decompress)

class GzipTest(unittest.TestCase, Tests):

    compress = staticmethod(zopfli.gzip.compress)
    
    def decompress(self, s):
        return gzip.GzipFile(fileobj=StringIO.StringIO(s)).read()
        

if __name__ == "__main__":
    unittest.main()
