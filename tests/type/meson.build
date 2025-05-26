type = executable(
  'type', 
  'type.cc',
  dependencies: [tornasol_dep, freetype_dep],
  link_with: tornasol_lib,
)

test(
  'type',
  type,
  timeout: 0,
)
