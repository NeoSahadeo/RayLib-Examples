project('raylib', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

source = {
  '01': 'src/01.c',
  '02': 'src/02.c',
  '03': 'src/03.c',
  '09': 'src/09.c',
  '10': 'src/10.c',
  '11': 'src/11.c',
}

raylib_dep = dependency('raylib')

# Apparently linux is the only platform with math std lb
cc = meson.get_compiler('c')
math_dep = cc.find_library('m', required: false)

foreach name, source : source
  executable(name, source, dependencies: [raylib_dep, math_dep])
endforeach
