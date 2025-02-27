project(
    'tornasol',
    ['c', 'cpp'],
    version: '0.1.0',
    license: 'zlib',
    subproject_dir: 'ext',
    default_options: [
        'cpp_std=c++latest',
        'warning_level=2',
        'default_library=static',
      ],
)

# Dependencies
gl_dep = dependency('gl')

entt_proj = subproject('entt')
entt_dep = entt_proj.get_variable('entt_dep')

freetype2_proj = subproject('freetype2')
freetype2_dep = freetype2_proj.get_variable('freetype_dep')

ogg_proj = subproject('ogg')
ogg_dep = ogg_proj.get_variable('libogg_dep')

vorbis_proj = subproject('vorbis')
vorbis_dep = vorbis_proj.get_variable('vorbis_dep')
vorbisfile_dep = vorbis_proj.get_variable('vorbisfile_dep')
vorbisenc_dep = vorbis_proj.get_variable('vorbisenc_dep')

sdl2_proj = subproject('sdl2')
sdl2_dep = sdl2_proj.get_variable('sdl2_dep')
sdl2main_dep = sdl2_proj.get_variable('sdl2main_dep')

sdl2_image_proj = subproject('sdl2_image')
sdl2_image_dep = sdl2_image_proj.get_variable('sdl2_image_dep')

sdl2_mixer_proj = subproject('sdl2_mixer')
sdl2_mixer_dep = sdl2_mixer_proj.get_variable('sdl2_mixer_dep')

sdl2_ttf_proj = subproject('sdl2_ttf')
sdl2_ttf_dep = sdl2_ttf_proj.get_variable('sdl2_ttf_dep')

glm_proj = subproject('glm')
glm_dep = glm_proj.get_variable('glm_dep')

tornasol_inc = include_directories('include')
tornasol_src = []
tornasol_deps = [
    gl_dep,
    glm_dep,
    freetype2_dep,
    ogg_dep,
    vorbis_dep,
    vorbisfile_dep,
    vorbisenc_dep,
    entt_dep,
    sdl2_dep,
    sdl2main_dep,
    sdl2_image_dep,
    sdl2_mixer_dep,
    sdl2_ttf_dep,
]

tornasol_dep = declare_dependency(
  include_directories : tornasol_inc,
  dependencies : tornasol_deps,
  link_with : [],
  link_args : [],
  compile_args : [],
)

if get_option('enable_tests')
  subdir('tests')
endif