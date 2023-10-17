# This line tells CMake that the project requires CMake version 3.16 or higher.
cmake_minimum_required(VERSION 3.16)

# This line creates a new CMake project called `my_project`.
project(my_project)

# This line adds an executable target to the project called `my_program`.
# The `main.cpp` file is the source file for the `my_program` target.
add_executable(my_program main.cpp)

# This line tells CMake to add the `include` directory to the include directories for the `my_program` target.
# This means that the `my_program` target will be able to find any header files that are located in the `include` directory.
target_include_directories(my_program PUBLIC include)

# This line tells CMake to link the `my_library` library to the `my_program` target.
# This means that the `my_program` target will be able to use the functions and variables that are defined in the `my_library` library.
target_link_libraries(my_program PUBLIC my_library)

# This line adds a static library target to the project called `my_library`.
# The `my_library.cpp` file is the source file for the `my_library` target.
add_library(my_library mylibrary.cpp)

# This line tells CMake to add the compile definition `MY_LIBRARY_VERSION=1.0.0` to the compile definitions for the `my_library` target.
# This means that the `my_library` target will be able to use the `MY_LIBRARY_VERSION` preprocessor macro.
# ?????
target_compile_definitions(my_library PRIVATE MY_LIBRARY_VERSION=1.0.0)

# This line tells CMake to add the `include` directory to the include directories for the `my_library` target.
# This means that the `my_library` target will be able to find any header files that are located in the `include` directory.
target_include_directories(my_library PUBLIC include)

# This line defines a configuration option called `BUILD_TESTS`. The default value of this option is `ON`.
option(BUILD_TESTS ON)

# This code block checks the value of the `BUILD_TESTS` configuration option. If the `BUILD_TESTS` configuration option is enabled, the code block adds an executable target to the project called `my_tests`. The `test.cpp` file is the source file for the `my_tests` target. The `my_tests` target also depends on the `my_library` and `my_program` targets. This means that the `my_tests` target will be able to use the functions and variables that are defined in the `my_library` and `my_program` targets.
if(BUILD_TESTS)
  add_executable(my_tests main.cpp)
  target_link_libraries(my_tests PRIVATE my_library my_program)
endif()
