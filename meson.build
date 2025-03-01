project(
    'tornasol',
    ['c', 'cpp'],
    version: '0.1.0',
    license: 'zlib',
    default_options: [
        'cpp_std=c++23,c++latest',
        'warning_level=2',
      ],
    meson_version: '>=1.1.0',
)

tornasol_deps = []

# OpenGL
gl_dep = dependency('gl')
tornasol_deps += gl_dep

# Entt
entt_proj = subproject('entt')
entt_dep = entt_proj.get_variable('entt_dep')
tornasol_deps += entt_dep

# Freetype
freetype2_proj = subproject('freetype2')
freetype2_dep = freetype2_proj.get_variable('freetype_dep')
tornasol_deps += freetype2_dep

# OGG
ogg_proj = subproject('ogg')
ogg_dep = ogg_proj.get_variable('libogg_dep')
tornasol_deps += ogg_dep

# Vorbis
vorbis_proj = subproject('vorbis')
vorbis_dep = vorbis_proj.get_variable('vorbis_dep')
vorbisfile_dep = vorbis_proj.get_variable('vorbisfile_dep')
vorbisenc_dep = vorbis_proj.get_variable('vorbisenc_dep')
tornasol_deps += vorbis_dep

# SDL2
sdl2_proj = subproject('sdl2')
sdl2_dep = sdl2_proj.get_variable('sdl2_dep')
tornasol_deps += sdl2_dep

if host_machine.system() == 'windows'
  sdl2main_dep = sdl2_proj.get_variable('sdl2main_dep')
  tornasol_deps += sdl2main_dep
endif

sdl2_image_proj = subproject('sdl2_image')
sdl2_image_dep = sdl2_image_proj.get_variable('sdl2_image_dep')
tornasol_deps += sdl2_image_dep

sdl2_mixer_proj = subproject('sdl2_mixer')
sdl2_mixer_dep = sdl2_mixer_proj.get_variable('sdl2_mixer_dep')
tornasol_deps += sdl2_mixer_dep

sdl2_ttf_proj = subproject('sdl2_ttf')
sdl2_ttf_dep = sdl2_ttf_proj.get_variable('sdl2_ttf_dep')
tornasol_deps += sdl2_ttf_dep

# GLM
glm_proj = subproject('glm')
glm_dep = glm_proj.get_variable('glm_dep')
tornasol_deps += glm_dep

tornasol_inc = include_directories('include')
tornasol_src = []

tornasol_dep = declare_dependency(
  include_directories : tornasol_inc,
  dependencies : tornasol_deps,
  link_with : [],
  link_args : [],
  compile_args : [],
)

# Testing
if get_option('enable_tests')
  subdir('tests')
endif
