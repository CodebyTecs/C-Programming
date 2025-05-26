# CMake generated Testfile for 
# Source directory: /Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7/example
# Build directory: /Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7/build/example
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(simple_test "simple_test")
set_tests_properties(simple_test PROPERTIES  _BACKTRACE_TRIPLES "/Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7/cmake/Modules/AddCMockaTest.cmake;116;add_test;/Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7/example/CMakeLists.txt;12;add_cmocka_test;/Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7/example/CMakeLists.txt;0;")
add_test(allocate_module_test "allocate_module_test")
set_tests_properties(allocate_module_test PROPERTIES  WILL_FAIL "1" _BACKTRACE_TRIPLES "/Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7/cmake/Modules/AddCMockaTest.cmake;116;add_test;/Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7/example/CMakeLists.txt;20;add_cmocka_test;/Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7/example/CMakeLists.txt;0;")
add_test(assert_macro_test "assert_macro_test")
set_tests_properties(assert_macro_test PROPERTIES  WILL_FAIL "1" _BACKTRACE_TRIPLES "/Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7/cmake/Modules/AddCMockaTest.cmake;116;add_test;/Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7/example/CMakeLists.txt;32;add_cmocka_test;/Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7/example/CMakeLists.txt;0;")
add_test(assert_module_test "assert_module_test")
set_tests_properties(assert_module_test PROPERTIES  WILL_FAIL "1" _BACKTRACE_TRIPLES "/Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7/cmake/Modules/AddCMockaTest.cmake;116;add_test;/Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7/example/CMakeLists.txt;44;add_cmocka_test;/Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7/example/CMakeLists.txt;0;")
subdirs("mock")
