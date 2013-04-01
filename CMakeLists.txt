cmake_minimum_required (VERSION 2.8)

add_library ( user_malloc SHARED user_malloc )
target_link_libraries ( user_malloc dl)

add_executable ( test test.c )
target_link_libraries ( test user_malloc c)
