# README

Most of the tasks are written in Main.cpp, classes in their respective files. 
Tests are provided in the tests/AnimalTests.cpp file.

## Requirements:

- Preferably Linux based system, not tested on Windows/Mac, 
although all the tools are available on these platforms.

- cmake 3.0 or higher

- gcc9.2

### Optional requirements for compiling with tests:

- vcpkg - https://github.com/microsoft/vcpkg

- git at least 2.9.x (vcpkg dependency)

- gtest (install through vcpkg)

    `./vcpkg install gtest`

## Building:

`./build.sh <YOUR_PATH_TO_VCPKG>`

To build without tests, simply do not provide the VCPKG path argument/cmake flag.

To build with tests, make sure you have vcpkg installed along with the gtest dependency. 
    
## Running

`./run.sh` to execute both tests and the application after compilation.

Unit tests only:

    ./build/bin/tests.out
    
Main application:

    ./build/bin/animals.out