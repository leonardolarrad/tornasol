project('glad', ['c','cpp'],
  version : '4.0.0',
  default_options : ['warning_level=1'],
)

glad_include = include_directories('include')
glad_src = [ 'src/glad.c', ]

glad_lib = static_library('glad',
  sources: glad_src,
  include_directories: glad_include,
  dependencies: [],
)

glad_dep = declare_dependency(
  include_directories: glad_include,
  link_with: [glad_lib],
)