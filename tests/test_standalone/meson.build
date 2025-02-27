test_standalone = executable(
  'test_standalone', 
  'test_standalone.cc',
  dependencies: [tornasol_dep],
  link_with: [],
  #win_subsystem: 'console',
)

test(
  'standalone',
  test_standalone,
  timeout: 0,
)