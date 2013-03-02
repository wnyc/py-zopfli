from __future__ import absolute_import

import zopfli.zopfli

def compress(data, *args, **kwargs):
    return zopfli.zopfli.gzip(data)
