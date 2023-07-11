# CMake generated Testfile for 
# Source directory: D:/WarGame/test
# Build directory: D:/WarGame/build/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(tests "D:/WarGame/build/test/Debug/tests.exe")
  set_tests_properties(tests PROPERTIES  _BACKTRACE_TRIPLES "D:/WarGame/test/CMakeLists.txt;13;add_test;D:/WarGame/test/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(tests "D:/WarGame/build/test/Release/tests.exe")
  set_tests_properties(tests PROPERTIES  _BACKTRACE_TRIPLES "D:/WarGame/test/CMakeLists.txt;13;add_test;D:/WarGame/test/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(tests "D:/WarGame/build/test/MinSizeRel/tests.exe")
  set_tests_properties(tests PROPERTIES  _BACKTRACE_TRIPLES "D:/WarGame/test/CMakeLists.txt;13;add_test;D:/WarGame/test/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(tests "D:/WarGame/build/test/RelWithDebInfo/tests.exe")
  set_tests_properties(tests PROPERTIES  _BACKTRACE_TRIPLES "D:/WarGame/test/CMakeLists.txt;13;add_test;D:/WarGame/test/CMakeLists.txt;0;")
else()
  add_test(tests NOT_AVAILABLE)
endif()
