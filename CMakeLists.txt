cmake_minimum_required (VERSION 3.11)

project(sub_variant)

add_executable(tests tests.cpp sub_variant.h)

set_target_properties(tests PROPERTIES CXX_STANDARD 17)
