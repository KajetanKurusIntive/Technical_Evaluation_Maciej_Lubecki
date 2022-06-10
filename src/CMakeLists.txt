file(
    GLOB 
    HEADERS ${HEADERS} 
    "Animal.h"
    "Constants.h"
    "Duck.h"
    "Functionality.h"
    "Goose.h"
    "Utils.h"
)
file(
    GLOB 
    SOURCES ${SOURCES}
    "Animal.cpp"
    "Duck.cpp"
    "Functionality.cpp"
    "Goose.cpp"
    "Utils.cpp"
)


set(SOURCES ${SOURCES} PARENT_SCOPE)
set(HEADERS ${HEADERS} PARENT_SCOPE)

add_library(${MAIN_LIBRARY_NAME} ${SOURCES} ${HEADERS})
