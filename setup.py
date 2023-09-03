from setuptools import setup, Extension
import os

if os.path.exists(os.path.join('src', 'EditDist.obj')):
    module = Extension('EditDist',
                sources=[os.path.join('src', 'pybindings.c')],
                extra_compile_args=['/O2'],
                extra_objects=[os.path.join('src', 'EditDist.obj')])
else:
    module = Extension('EditDist',
                sources=[os.path.join('src', 'pybindings.c'), os.path.join('src', 'EditDist.c')],
                extra_compile_args=['/O2'])

setup(name='EditDist',
    version='1.0',
    description='Calculate the edit distance between two strings',
    ext_modules=[module])