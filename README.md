# CloudWalk Software Enginner Test

This project aims solve a Test to Software Engineering positions at CloudWalk.

It's composed by a parser which reads Quake 3 Arena log and groups game data of the matches.
In addition, a script was developed to collect game data and show it readable on screen.

## Dependencies

#### CMake 
[CMake](https://cmake.org/) was used to manage the build process. That way we can easily change the compiler and the operating system without further reworks.

Installation suggestion:
```bash
    sudo apt-get install cmake
```

#### googletest
The [googletest](https://github.com/google/googletest) was the framework chosen to orchestrate the unit test due developer's prior knowledge.

Installation suggestion:
```bash
    sudo apt-get install googletest
```

## Getting started

To reproduce the environment get the source code:
```bash
    git clone https://gitlab.com/albmiranda/logparser.git
    cd logparser
```

Now you are ready to compile the code:
```bash
    mkdir build
    cd build

    # choose the build type
    cmake ../ ## for release build - this option make all warnings into errors and turns on all optimizations
    #or
    cmake -DCMAKE_BUILD_TYPE=Debug ../ ## for debug build - this options shows debug information on compile time and include symbols into the binary.

    make -j4
    make install
```

## Usage
Once you get started application binary will be delivered to \${PROJECT_ROOT}/bin as **logparser**.
```bash
   ./bin/logparser
```
Run it and a file match.rec whithin \${PROJECT_ROOT}/out will be created to store the game data. Later that file is use by a script to summarize the game data.

#### Memory Leak detection

This project aims to free all heap blocks. To achieve it the valgring was used. To validate results type:
```bash
   valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./bin/logparser
```

## Tests

To increase reliability the source code has been subjected to unit testing.
A unit test application will be available after regular [compile](#getting-started) as well, to run it just type:.
```bash
   ctest --verbose
```

The code coverage was identified by gcov/lcov tools.
> Overall coverage rate:
  lines......: 90.4% (104 of 115 lines)
  functions..: 96.0% (24 of 25 functions)

To reach this values just type:
```bash
   ./build/test/logparser_test
   lcov --capture --directory ./build/src --output-file coverage.info
   lcov -r coverage.info /usr/include/\* -o coverage_clean.info
   genhtml coverage_clean.info --output-directory codecoverage
```

## Backlog - Future features

This project scope still covers some features which wasn't developed at this time. Following some of them:
* Pipeline CI/CD
* End-to-end tests

# Thank you!