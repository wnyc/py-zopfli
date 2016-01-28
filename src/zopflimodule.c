#define PY_SSIZE_T_CLEAN size_t
#include <Python.h>
#include <stdlib.h>
#include "../zopfli/src/zopfli/zlib_container.h"
#include "../zopfli/src/zopfli/gzip_container.h"
#include "../zopfli/src/zopfli/util.h"


static PyObject *
zopfli_compress(PyObject *self, PyObject *args, PyObject *keywrds)
{
  const unsigned char *in;
  unsigned char *in2, *out;
  size_t insize=0; 
  size_t outsize=0;
  ZopfliOptions options;
  int gzip_mode = 0;
  static char *kwlist[] = {"data", "verbose", "numiterations", "blocksplitting", "blocksplittinglast", "blocksplittingmax", "gzip_mode", NULL};
  PyObject *returnValue;

  ZopfliInitOptions(&options);
  options.verbose = 0;
  options.numiterations = 15;
  options.blocksplitting = 1;
  options.blocksplittinglast = 0;
  options.blocksplittingmax = 15;
  
  if (!PyArg_ParseTupleAndKeywords(args, keywrds, "s#|iiiiii", kwlist, &in, &insize,
                                   &options.verbose,
                                   &options.numiterations,
                                   &options.blocksplitting,
                                   &options.blocksplittinglast,
                                   &options.blocksplittingmax,
                                   &gzip_mode))
    return NULL;

  Py_BEGIN_ALLOW_THREADS
  in2 = malloc(insize);
  memcpy(in2, in, insize);

  if (!gzip_mode) 
    ZopfliZlibCompress(&options, in2, insize, &out, &outsize);
  else 
    ZopfliGzipCompress(&options, in2, insize, &out, &outsize);
  
  free(in2);
  Py_END_ALLOW_THREADS

  returnValue = Py_BuildValue("s#", out, outsize);
  free(out);
  return returnValue;
}


static char docstring[] = "" 
  "zopfli.zopfli.compress applies zopfli zip or gzip compression to an obj." 
  "" \
  "zopfli.zopfli.compress("
  "  s, **kwargs, verbose=0, numiterations=15, blocksplitting=1, "
  "  blocksplittinglast=0, blocksplittingmax=15, gzip_mode=0)"
  ""
  "If gzip_mode is set to a non-zero value, a Gzip compatbile container will "
  "be generated, otherwise a zlib compatible container will be generated. ";


static PyObject *ZopfliError;

static PyMethodDef ZopfliMethods[] = {
  { "compress", (PyCFunction)zopfli_compress,  METH_KEYWORDS, docstring},

  { NULL, NULL, 0, NULL}
};


PyMODINIT_FUNC
initzopfli(void)
{
  PyObject *m;

  m = Py_InitModule("zopfli", ZopfliMethods);
  if (m == NULL) 
    return;

  ZopfliError = PyErr_NewException("zopfli.error", NULL, NULL);
  Py_INCREF(ZopfliError);
  PyModule_AddObject(m, "error", ZopfliError);
}

