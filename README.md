# CloudWalk Software Enginner Test

This project aims solve a Test to Software Engineering positions at CloudWalk.

It's composed by a parser which reads Quake 3 Arena log and groups game data of the matches.
In addition, a script was developed to collect game data and show it readable on screen.

The workflow was based on [gitflow](https://www.atlassian.com/git/tutorials/comparing-workflows/gitflow-workflow), actually it's more like a reduced-gitflow with no feature branch due reduced number of features.
The versioning follow [semantic version](https://semver.org/)

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

There is a script to print a report for matches and a player ranking. This script was written in Python. To see it type:
```bash
   python3 script/report.py
```

#### Memory Leak detection

This project aims to free all heap blocks. To achieve it the valgring was used. To validate results type:
```bash
   valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./bin/logparser
```

## Tests

To increase reliability the source code has been subjected to unit testing.
A unit test application will be available after regular [compile](#getting-started) as well, to run it just type:.
```bash
   cd build
   ctest --verbose
```

The code coverage was identified by gcov/lcov tools.
> Summary coverage rate:
  lines......: 97.4% (152 of 156 lines)
  functions..: 100.0% (28 of 28 functions)
  branches...: no data found

To reach this values just build the application in debug mode and then type:
```bash
    cd build
   ./test/logparser_test
   lcov --capture --directory ./src --output-file coverage.info
   lcov -r coverage.info /usr/include/\* -o coverage_clean.info
   genhtml coverage_clean.info --output-directory codecoverage
```

## Backlog - Future features

This project scope still covers some features which wasn't developed at this time. Following some of them:
* End-to-end tests
* CD pipeline

# Thank you!