#include <Python.h>
#include <stdlib.h>
#include "zlib_container.h"
#include "gzip_container.h"
#include "util.h"


static PyObject *
zopfli_zlib_compress(PyObject *self, PyObject *args)
{
  const unsigned char *in;
  unsigned char *in2, *out;
  size_t insize=0; 
  size_t outsize=0;  
  if (!PyArg_ParseTuple(args, "s#", &in, &insize))
    return NULL;
  Py_BEGIN_ALLOW_THREADS
    
  Options options;
  InitOptions(&options);
  options.verbose = 0;
  options.numiterations = 15;
  options.blocksplitting = 1;
  options.blocksplittinglast = 0;
  options.blocksplittingmax = 15;
  in2 = malloc(insize);
  memcpy(in2, in, insize);
  ZlibCompress(&options, in2, insize, &out, &outsize);
  
  free(in2);
  Py_END_ALLOW_THREADS
  
  PyObject *returnValue;
  returnValue = Py_BuildValue("s#", out, outsize);
  free(out);
  return returnValue;
}

static PyObject *
zopfli_gzip_compress(PyObject *self, PyObject *args)
{
  const unsigned char *in;
  unsigned char *in2, *out;
  size_t insize=0; 
  size_t outsize=0;  
  if (!PyArg_ParseTuple(args, "s#", &in, &insize))
    return NULL;
  Py_BEGIN_ALLOW_THREADS
    
  Options options;
  InitOptions(&options);
  options.verbose = 0;
  options.numiterations = 15;
  options.blocksplitting = 1;
  options.blocksplittinglast = 0;
  options.blocksplittingmax = 15;
  in2 = malloc(insize);
  memcpy(in2, in, insize);
  GzipCompress(&options, in2, insize, &out, &outsize);
  
  free(in2);
  Py_END_ALLOW_THREADS
  
  PyObject *returnValue;
  returnValue = Py_BuildValue("s#", out, outsize);
  free(out);
  return returnValue;
}


static PyObject *ZopfliError;

static PyMethodDef ZopfliMethods[] = {
  { "zlib", zopfli_zlib_compress, METH_VARARGS, "Perform zlib compression" },
  { "gzip", zopfli_gzip_compress, METH_VARARGS, "Perform gzip compression" },

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

