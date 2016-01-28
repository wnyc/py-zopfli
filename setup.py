#!/usr/bin/env python
"""
pyzopfli
======

Python bindings to zopfli
"""

from setuptools import setup, Extension

setup(
    name='zopfli',
    version='0.0.4',
    author='Adam DePrince',
    author_email='adeprince@nypublicradio.org',
    description='Zopfli module for python',
    long_description=__doc__,
    ext_modules = [Extension('zopfli.zopfli',
                             sources = [
                                 'zopfli/src/zopfli/blocksplitter.c',
                                 'zopfli/src/zopfli/cache.c',
                                 'zopfli/src/zopfli/deflate.c',
                                 'zopfli/src/zopfli/gzip_container.c',
                                 'zopfli/src/zopfli/squeeze.c',
                                 'zopfli/src/zopfli/hash.c',
                                 'zopfli/src/zopfli/katajainen.c',
                                 'zopfli/src/zopfli/lz77.c', 
                                 'zopfli/src/zopfli/tree.c',
                                 'zopfli/src/zopfli/util.c',
                                 'zopfli/src/zopfli/zlib_container.c',
                                 'src/zopflimodule.c',
                ],
                             )],
    package_dir={"": "src"},
    packages = ["zopfli"],
    zip_safe=True,
    license='ASL',
    include_package_data=True,
    classifiers=[
        'Intended Audience :: Developers',
        'License :: OSI Approved :: Apache Software License',
        'Programming Language :: Python :: Implementation :: CPython',
        'Topic :: System :: Archiving :: Compression',
        ],
    url = "https://github.com/wnyc/py-zopfli",
    test_suite="tests",
)

