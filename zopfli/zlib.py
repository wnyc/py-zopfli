from __future__ import absolute_import

import zopfli.zopfli

def compress(data, *args, **kwargs):
    kwargs['gzip_mode'] = 0
    return zopfli.zopfli.compress(data, *args, **kwargs)
