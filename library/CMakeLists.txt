set(TARGET library)

set(SOURCES
  ast_calculator.cpp
  calculator.cpp
  parser.cpp)

add_library(${TARGET} STATIC
  ${SOURCES})

target_compile_options(${TARGET}
  PRIVATE
    -Wall
    -Werror)

target_include_directories(${TARGET}
  INTERFACE
    include
  PUBLIC
    ${Boost_INCLUDE_DIR}
  PRIVATE
    include/${TARGET})

add_custom_command(TARGET ${TARGET} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR})
