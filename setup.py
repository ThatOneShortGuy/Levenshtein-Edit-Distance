from setuptools import setup, Extension

module = Extension('EditDist',
             sources=['pybindings.c'],
             extra_compile_args=['/O2'],
             extra_objects=['EditDist.obj'])

setup(name='EditDist',
    version='1.0',
    description='Calculate the edit distance between two strings',
    ext_modules=[module])