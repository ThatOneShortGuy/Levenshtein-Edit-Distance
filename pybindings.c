#include <Python.h>
#include <stdio.h>
#include <stdlib.h>

#include "EditDist.h"

static PyObject *compute_distc(PyObject *self, PyObject *args) {
    PyObject *word1, *word2;

    if (!PyArg_ParseTuple(args, "OO", &word1, &word2)) {
        return NULL;
    }

    size_t word1_len = PyUnicode_GetLength(word1);
    size_t word2_len = PyUnicode_GetLength(word2);

    wchar_t *word1_str = PyUnicode_AsWideCharString(word1, &word1_len);
    wchar_t *word2_str = PyUnicode_AsWideCharString(word2, &word2_len);
    
    return Py_BuildValue("i", compute_dist_wchar(word1_str, word2_str));
}

static PyObject *version(PyObject *self) {
    return Py_BuildValue("s", "Version 1.0");
}

static PyMethodDef myMethods[] = {
    {"compute_dist", (PyCFunction)compute_distc, METH_VARARGS, "Computes the edit distance between two words."},
    {"version", (PyCFunction)version, METH_NOARGS, "Returns the version."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT, // Must be there, initializer
    "EditDist", // Name of the module
    "Edit Distance Module to access all the performance critical portions of the Edit Distance", // Docs
    -1, // Size of per-interpreter state of the module, or -1 if the module keeps state in global variables | Global state
    myMethods // The methods of the module
};

// The initialization function
PyMODINIT_FUNC PyInit_EditDist(void) {
    return PyModule_Create(&myModule);
}