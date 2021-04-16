include(CTest)
find_package(GTest)

enable_testing()

set(TARGET tests)

set(SOURCES
  main.cpp
  test-calculator.cpp)

add_executable(${TARGET}
  "${SOURCES}")

target_compile_options(${TARGET}
  PRIVATE
    -Wall
    -Werror)

target_link_libraries(${TARGET}
  PRIVATE
    GTest::GTest
    library)

gtest_discover_tests(${TARGET})

add_custom_command(TARGET ${TARGET} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/${TARGET}/data 
  ${PROJECT_BINARY_DIR}/${TARGET})

