# CoMeta

[![Build Status](https://travis-ci.org/kfrlib/cometa.svg?branch=master)](https://travis-ci.org/kfrlib/cometa)

Lightweight, header-only C++14 metaprogramming library.
Created for [KFR framework](https://github.com/kfrlib/kfr).

## Features

* Pattern matching
* Compile-time arrays
* Compile-time type information (CTTI)
* Compile-time string manipulation
* Compile-time operations on arrays and numbers
* 'value-or-errorcode' union-like type
* type for passing named arguments
* function wrapper (lightweight replacement for std::function)
* Useful constexpr functions and many more.

## Platform

CoMeta is platform-independent but modern C++14 compiler is required.

* AppleClang (XCode 7, 8)
* Clang 3.7 or newer
* GCC 5.1 or newer

## Tests

See `tests/cometa_test.cpp`

## License
MIT

See LICENSE for details
