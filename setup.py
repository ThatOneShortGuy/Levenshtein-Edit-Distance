from setuptools import setup, Extension
import os

if os.path.exists('EditDist.obj'):
    module = Extension('EditDist',
                sources=['pybindings.c'],
                extra_compile_args=['/O2'],
                extra_objects=['EditDist.obj'])
else:
    module = Extension('EditDist',
                sources=['pybindings.c', 'EditDist.c'],
                extra_compile_args=['/O2'])

setup(name='EditDist',
    version='1.0',
    description='Calculate the edit distance between two strings',
    ext_modules=[module])