project('Literally', 'cpp', version : '0.0.1_pre-alpha')

deps = [dependency('sdl2')]
incdir = include_directories('include')

subdir('src/Engine')

sources = ['src/main.cpp']

executable('Literally', sources, dependencies : deps, include_directories : incdir, link_with : libs)