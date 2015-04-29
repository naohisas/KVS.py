#!/usr/bin/env python
import os
from distutils.core import setup, Extension

KVS_DIR = os.environ.get('KVS_DIR')
KVS_INC_DIR = KVS_DIR + '/include'
KVS_LIB_DIR = KVS_DIR + '/lib'

module = Extension(
    'kvs',
    sources = [
        'Source/kvs.cpp'],
    include_dirs = [
        '/usr/local/include/',
        KVS_INC_DIR],
    library_dirs = [
        '/usr/local/lib',
        KVS_LIB_DIR],
    libraries = [
        'GLEW',
        'boost_python-mt',
        'kvsSupportGLUT',
        'kvsCore'],
    extra_link_args = [
        '-framework', 'OpenGL',
        '-framework', 'GLUT']
)

setup(
    name = 'kvs',
    ext_modules = [module]
)
