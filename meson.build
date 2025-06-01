project(
  'tornasol',
  ['c', 'cpp'],
  version: '0.1.0',
  license: 'zlib',
  default_options: [
      'cpp_std=c++23,c++latest',
      'warning_level=3',
      'default_library=shared',
    ],
  meson_version: '>=1.1.0',
  subproject_dir: '3rdparty',
)

## Dependencies

tornasol_deps = []
tornasol_cpp_args = []

glfw_proj = subproject(
  'glfw', 
  default_options: 'default_library=shared', 
  required: true
)
add_project_arguments('-DGLFW_DLL', language: ['c','cpp'])
glfw_dep = glfw_proj.get_variable('glfw_dep')
tornasol_deps += glfw_dep

glm_proj = subproject('glm', required: true)
glm_dep = glm_proj.get_variable('glm_dep')
tornasol_deps += glm_dep

glad_proj = subproject('glad', required: true)
glad_dep = glad_proj.get_variable('glad_dep')
tornasol_deps += glad_dep

freetype_proj = subproject('freetype2', required: true)
freetype_dep = freetype_proj.get_variable('freetype_dep')
#tornasol_deps += freetype_dep

## Library

tornasol_inc = include_directories('include')
tornasol_src = [
  'src/engine.cc',
  'src/window.cc',
  'src/opengl.cc',
]

if get_option('default_library') != 'static'
  tornasol_cpp_args += '-D_TORNASOL_BUILD_SHARED'
  add_project_arguments('-DTORNASOL_SHARED', language: ['c','cpp'])  
endif

tornasol_lib = library(
  'tornasol',
  tornasol_src,
  include_directories: tornasol_inc,
  dependencies: tornasol_deps,
  cpp_args: tornasol_cpp_args,
  install: true
)

tornasol_dep = declare_dependency(
  include_directories: [tornasol_inc],
  link_with: tornasol_lib,
  dependencies: [glm_dep, glad_dep] # Header-only deps.
)

## Testing

if get_option('enable_tests')
  subdir('tests/prototype')
  subdir('tests/type')
  subdir('tests/basic')
endif
