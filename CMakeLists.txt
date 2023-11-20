cmake_minimum_required(VERSION 3.16)
project(my_proj LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

#add_subdirectory(${DEP_PATH}/fm)
#add_subdirectory(${DEP_PATH}/LBVH)
#add_subdirectory(${DEP_PATH}/graphics)

file(GLOB_RECURSE cpp_sources 
  ${PROJECT_SOURCE_DIR}/inc/*.hpp 
  ${PROJECT_SOURCE_DIR}/src/*.hpp 
  ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_library(${CMAKE_PROJECT_NAME} ${cpp_sources})
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)

if (my_proj_ENABLE_ASAN)
  add_link_options(-fsanitize=address)
  add_compile_options(-fsanitize=address)
endif()

if (my_proj_ENABLE_TESTING)
  add_subdirectory(tests)
endif()
