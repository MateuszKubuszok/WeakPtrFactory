import os
import SCons.Tool

env = Environment()
env['CC']          = os.getenv('CC')   or env['CC']
env['CXX']         = os.getenv('CXX')  or env['CXX']
env['ENV']['PATH'] = os.getenv('PATH') or env['ENV']['PATH']
env['ENV'].update(x for x in os.environ.items() if x[0].startswith('CCC_'))

env.Append(
  CPPFLAGS = [ '-std=c++11', '-Wall', '-Wextra', '-Werror', '-pedantic-errors' ],
  CPPPATH  = [ './']
)

test_program = env.Program(
  source='./test/weak_ptr_factory_test.cpp',
  target='./bin/test'
)

test_run = Command(
  source=test_program,
  target='test-mock-content',
  action='./bin/test'
)
AlwaysBuild(test_run)
