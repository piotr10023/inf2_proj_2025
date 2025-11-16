cmake_minimum_required(VERSION 3.10)
project(p_inf_sem_3)

set(CMAKE_CXX_STANDARD 14)

# SFML jest w folderze projektu - popraw ścieżkę
set(SFML_DIR ${CMAKE_SOURCE_DIR}/SFML-2.6.2/lib/cmake/SFML)

find_package(SFML 2.6 COMPONENTS system window graphics REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/SFML-2.6.2/include)