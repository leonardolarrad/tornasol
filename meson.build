project(
  'tornasol',
  ['c', 'cpp'],
  version: '0.1.0',
  license: 'zlib',
  default_options: [
      'cpp_std=c++23,c++latest',
      'warning_level=3',
    ],
  meson_version: '>=1.1.0',
  subproject_dir : '3rdparty',
)

tornasol_inc = include_directories('include')
tornasol_src = []
tornasol_deps = []

tornasol_deps += [
  subproject('glad').get_variable('glad_dep'),
  subproject('glm').get_variable('glm_dep'),
  subproject('glfw').get_variable('glfw_dep'),
  subproject('freetype2').get_variable('freetype_dep'),
]

tornasol_dep = declare_dependency(
  include_directories : tornasol_inc,
  dependencies : tornasol_deps,
  link_with : [],
  link_args : [],
  compile_args : [],
)

# Testing
if get_option('enable_tests')
  subdir('tests/prototype')
endif
