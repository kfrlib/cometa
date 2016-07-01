# Copyright (C) 2016 D Levin (http://www.kfrlib.com)
# This file is part of CoMeta (C++14 metaprogramming library created for KFR framework)
# License: MIT

cmake_minimum_required(VERSION 2.8)

if (CMAKE_BUILD_TYPE_INITIALIZED_TO_DEFAULT)
    set(CMAKE_BUILD_TYPE Release)
endif ()

project(cometa)

include_directories(include)

set(SRC
    include/cometa.hpp
    include/cident.h
    include/cometa/string.hpp
)

add_compile_options(-std=c++1y -Wall -fno-exceptions -fno-rtti)

add_executable(cometa_test tests/cometa_test.cpp ${SRC})
