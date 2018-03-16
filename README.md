[![Build Status](https://travis-ci.org/Altgear/vector_example.svg?branch=probe)](https://travis-ci.org/Altgear/vector_example)

```
cmake -H. -B_builds -DBUILD_TESTS=ON
cmake --build _builds
cmake --build _builds --target test -- ARGS=--verbose
```
