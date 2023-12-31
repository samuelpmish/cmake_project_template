enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.tar.gz
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE cpp_tests ${PROJECT_SOURCE_DIR}/tests/*.cpp)

foreach(filename ${cpp_tests})		

  get_filename_component(testname ${filename} NAME_WE)

  add_executable(${testname} ${filename})
  target_link_libraries(${testname} PUBLIC ${CMAKE_PROJECT_NAME} GTest::gtest_main)
  #target_precompile_headers(${testname} REUSE_FROM pch)

  add_test(${testname} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${testname})		

endforeach(filename ${cpp_tests})
